#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <io.h>
#ifndef WIN32
#include "StringBuffer.h"
#endif
#include "IniFile.h"


//Type definition line
#define LINE_TYPE_EMPTY			0	//Blank lines
#define LINE_TYPE_COMMENT		1	//Comments
#define LINE_TYPE_SECTION		2	//Regional
#define LINE_TYPE_KEY			3	//Configuration Item

//Constructor
CIniFile::CIniFile()
{
	m_sFileName = "";
	m_nTotalSection = 0;
	m_bAutoFlush = true;
	m_bModified = false;

}
CIniFile::CIniFile(const char* sFileName)
{
	m_sFileName = "";
	m_nTotalSection = 0;
	m_bAutoFlush = true;
	m_bModified = false;

	LoadFromFile(sFileName);
}
//Destructor
CIniFile::~CIniFile()
{
	Reset();
}
//Re-initialization of the object
void CIniFile::Reset(void)
{
	//First Save
	if(m_bAutoFlush)
		FlushToFile();
	
	//Remove all objects
	struct LINE_ITEM *pItem;
	for(int i = m_arrayOfLine.GetSize() - 1; i >= 0; i --)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem)
			delete pItem;
	}
	m_arrayOfLine.RemoveAll();

	m_sFileName = "";
        m_nTotalSection = 0;
	m_bAutoFlush = true;
}

//Load profile
int CIniFile::LoadFromFile(const char* sFileName)
{
	//Reset
	Reset();
	m_sFileName = sFileName;

	//Open the file
	FILE *fp = fopen(sFileName, "r");
	if(fp == NULL)
		return -1;
	
	//Read the file
	char sBuffer[1024];
	char *sTemp, *sFind;
	int nLength;

	fseek(fp, 0, SEEK_SET);
	while(! feof(fp))
	{
		sTemp = fgets(sBuffer, sizeof(sBuffer), fp);
		if(sTemp == NULL)
			break;
		for(;*sTemp == ' ' || *sTemp == '\t'; sTemp ++);
		nLength = strlen(sTemp);
		if(nLength == 0)
		{
			continue;
		}
		if(sTemp[nLength - 1] == '\n')
		{
			sTemp[nLength - 1] = 0;
			nLength --;
		}
		if(sTemp[nLength - 1] == '\r')
		{
			sTemp[nLength - 1] = 0;
			nLength --;
		}
					
		struct LINE_ITEM *pItem = new struct LINE_ITEM;
		switch(*sTemp)
		{
			case ';':
			case '#':
				pItem->nType = LINE_TYPE_COMMENT;
				pItem->sName = sTemp;
				break;
			case 0:
				pItem->nType = LINE_TYPE_EMPTY;
				break;
			case '[':
				for(sTemp ++; *sTemp == ' ' || *sTemp == '\t'; sTemp ++);
				sFind = strchr(sTemp, ']');
				if(sFind == NULL)
					pItem->nType = LINE_TYPE_COMMENT;
				else
				{
					for(sFind --; sFind != sTemp && (*sFind == ' ' || *sFind == '\t'); sFind --);
					pItem->nType = LINE_TYPE_SECTION;
					*(sFind + 1) = 0;

					m_nTotalSection ++;
				}
				pItem->sName = sTemp;
				break;
			default:
				sFind = strchr(sTemp, '=');
				if(sFind == NULL)
				{
					pItem->nType = LINE_TYPE_COMMENT;
					pItem->sName = sTemp;
				}
				else
				{
					char *sMiddle = sFind + 1;
					for(sFind --; sFind != sTemp && (*sFind == ' ' || *sFind == '\t'); sFind --);
					*(sFind + 1) = 0;
					
					pItem->nType = LINE_TYPE_KEY;
					pItem->sName = sTemp;

					for(; *sMiddle == ' ' || *sMiddle == '\t'; sMiddle ++);
					pItem->sValue = sMiddle;
				}
				break;
		}//switch
		
		m_arrayOfLine.Add(pItem);
	}//while;

	fclose(fp);
	return 0;
}
//Refresh the current configuration items to file returns 0 on success, failure to return a value of 0 is involved in
int CIniFile::FlushToFile(void)
{
	//To determine whether changes
	if(! m_bModified )
		return 0;

	//Open the file
	FILE *fp = fopen(m_sFileName, "w");
	if(fp == NULL)
		return -1;

	//Write to file
	struct LINE_ITEM *pItem;
	for(int i = 0; i < m_arrayOfLine.GetSize(); i ++)	
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem) switch(pItem->nType)
		{
			case LINE_TYPE_COMMENT:
				fprintf(fp, "%s\r\n", (const char*)pItem->sName);
				break;
			case LINE_TYPE_EMPTY:
				fprintf(fp, "\r\n");
				break;
			case LINE_TYPE_SECTION:
				fprintf(fp, "[%s]\r\n", (const char*)pItem->sName);
				break;
			case LINE_TYPE_KEY:
				fprintf(fp, "%s=%s\r\n", (const char*)pItem->sName, (const char*)pItem->sValue);
				break;
		}
	}

	fclose(fp);
	m_bModified = false;
	return 0;
}
//According to the zone name, get the line number
int CIniFile::GetSectionIndex(int nStartLine, const char* sSectionName)
{
	struct LINE_ITEM *pItem;
	for(int i = nStartLine; i < m_arrayOfLine.GetSize(); i ++)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem && pItem->nType == LINE_TYPE_SECTION && pItem->sName.CompareNoCase(sSectionName) == 0)
				return i;
	}

	return -1;
}
//According to the regional line number and configuration item name, get the line number where the configuration items
int CIniFile::GetKeyIndex(int nSectionIndex, const char* sKeyName)
{
	struct LINE_ITEM *pItem;
	for(int i = nSectionIndex + 1; i < m_arrayOfLine.GetSize(); i ++)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem)
		{
			if(pItem->nType == LINE_TYPE_SECTION)
				break;
			if(pItem->nType == LINE_TYPE_KEY && pItem->sName.CompareNoCase(sKeyName) == 0)
				return i;
		}
	}	
	
	return -1;
}

//Obtain the total number of regions
int CIniFile::GetSectionCount(void)
{
	return m_nTotalSection;
}
//Get zone name
CString CIniFile::GetSectionName(int nIndex)
{
	struct LINE_ITEM *pItem;
	for(int i = 0; i < m_arrayOfLine.GetSize(); i ++)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem && pItem->nType == LINE_TYPE_SECTION )
			if(nIndex == 0)
				return pItem->sName;
			else
				nIndex --;
	}

	return "";
}
//Obtain the total number of configuration items in the designated area
int CIniFile::GetKeyCount(const char* sSectionName)
{
	struct LINE_ITEM *pItem;
	int i = GetSectionIndex(0, sSectionName);
	int nTotalKey = 0;
	if(i >= 0) for(i ++; i < m_arrayOfLine.GetSize(); i ++)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem )
		{
			if(pItem->nType == LINE_TYPE_SECTION )
				break;
			if(pItem->nType == LINE_TYPE_KEY)
				nTotalKey ++;
		}
	}

	return nTotalKey;
}
//Obtain configuration item name
CString CIniFile::GetKeyName(const char* sSectionName, int nIndex)
{
	struct LINE_ITEM *pItem;
	int i = GetSectionIndex(0, sSectionName);
	if(i >= 0) for(i++; i < m_arrayOfLine.GetSize(); i ++)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem )
		{
			if(pItem->nType == LINE_TYPE_SECTION )
				break;
			if(pItem->nType == LINE_TYPE_KEY)
				if(nIndex == 0)
					return pItem->sName;
				else
					nIndex --;
		}
	}

	return "";
}
//To delete a configuration item
int CIniFile::DelKey(const char* sSectionName, const char* sKeyName)
{
	int nSectionIndex = GetSectionIndex(-1, sSectionName);
	if(nSectionIndex >= 0)
	{
		int nKeyIndex = this->GetKeyIndex(nSectionIndex, sKeyName);
		if(nKeyIndex >= 0)
		{
			struct LINE_ITEM *pItem;
			pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(nKeyIndex);
			m_arrayOfLine.RemoveAt(nKeyIndex);
			if(pItem)
				delete pItem;

			m_bModified = true;
			if(m_bAutoFlush)
				FlushToFile();
		}

		return nKeyIndex;
	}

	return -1;
}

//Increase in one area, the return index value, failed to return a value less than 0
int CIniFile::AddSection(const char* sSectionName)
{
	int i = GetSectionIndex(0,sSectionName);
	if(i >= 0)
		return i;
	else
	{
		struct LINE_ITEM *pItem  = new struct LINE_ITEM;
		pItem->nType = LINE_TYPE_SECTION;
		pItem->sName = sSectionName;
		i = m_arrayOfLine.Add(pItem);

		m_bModified = true;
		if(m_bAutoFlush)
			FlushToFile();

		return i;
	}
}
//To delete a region
void CIniFile::DelSection(const char* sSectionName)
{
	int i = GetSectionIndex(0,sSectionName);
	struct LINE_ITEM *pItem;
	if(i >= 0) 
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		m_arrayOfLine.RemoveAt(i);
		if(pItem)
			delete pItem;
		
		for(; i < m_arrayOfLine.GetSize(); i)
		{
			pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
			if(pItem && pItem->nType == LINE_TYPE_SECTION )
					break;
			else
			{
				if(pItem)
					delete pItem;
				m_arrayOfLine.RemoveAt(i);
			}
		}

		m_bModified = true;
		if(m_bAutoFlush)
			FlushToFile();
	}
}
	
//Configuration item value method of operation
//Obtain configuration item value (string)
CString CIniFile::GetString(const char* sSectionName, const char* sKeyName)
{
	int i = GetSectionIndex(0,sSectionName);
	if(i >= 0)
		i = GetKeyIndex(i, sKeyName);
	if(i >= 0)
	{
		struct LINE_ITEM *pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(i);
		if(pItem)
			return pItem->sValue;
	}

	return "";
}
//Obtain configuration item value (integer)
int CIniFile::GetInt(const char* sSectionName, const char* sKeyName)
{
	return atoi(GetString(sSectionName, sKeyName));
}
//Obtain the value of configuration items (Boolean)
bool CIniFile::GetBool(const char* sSectionName, const char* sKeyName)
{
	if(GetInt(sSectionName, sKeyName) == 0)
		return false;
	else
		return true;
}
//Set the value of configuration items (string)
void CIniFile::SetString(const char* sSectionName, const char* sKeyName, const char* sKeyValue)
{
	int i = GetSectionIndex(0,sSectionName);
	int j;
	if(i < 0)
		i = AddSection(sSectionName);
	if(i >= 0)
		j = GetKeyIndex(i, sKeyName);
	else 
		return;
	
	struct LINE_ITEM *pItem;
	if(j >= 0)
	{
		pItem = (struct LINE_ITEM *)m_arrayOfLine.GetAt(j);
		pItem->sValue = sKeyValue;
	}
	else
	{
		pItem = new struct LINE_ITEM;
		pItem->nType = LINE_TYPE_KEY;
		pItem->sName = sKeyName;
		pItem->sValue = sKeyValue;
		m_arrayOfLine.InsertAt(i + 1, pItem);
		j = i+1;
	}
	if(j >= 0)
		m_bModified = true;
	if(m_bAutoFlush)
		FlushToFile();
}
//Setting configuration item value (integer)
void CIniFile::SetInt(const char* sSectionName, const char* sKeyName, int nKeyValue)
{
	char sBuffer[256];
	sprintf(sBuffer, "%d", nKeyValue);
	SetString(sSectionName, sKeyName, sBuffer);
}
//Set the value of the configuration items (Boolean)
void CIniFile::SetBool(const char* sSectionName, const char* sKeyName, bool bKeyValue)
{
	if(bKeyValue)
		SetString(sSectionName, sKeyName, "1");
	else
		SetString(sSectionName, sKeyName, "0");
}

