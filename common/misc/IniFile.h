/********************************************************************
	created:	2008/01/11
	created:	11:1:2008   15:49
	author:		Kevin
	
	purpose:	

	email:		kan8888.com@163.com
	msn:		fuwenke@gmail.com
	QQ:		799383417
	site:		opensource.kan8888.com
*********************************************************************/
#ifndef __INI_FILE_H_
#define __INI_FILE_H_


#include "StringBuffer.h"

#include "Array.h"

using namespace KBASE;

/*Custom Actions class*/
class CIniFile
{
//Structure and destructor
public:
	CIniFile();
	CIniFile(const char* sFileName);
	virtual ~CIniFile();

//Definition of private data members
protected:
	//Definition line structure
	struct LINE_ITEM
	{
		int 	nType;		//Type
		CString	sName;		//Name
		CString sValue;		//Value
	};
	CPtrArray   	m_arrayOfLine;	//Stored in the configuration file for all lines
	CString			m_sFileName;	//Profile name
	int				m_nTotalSection;//The total number of regions
	bool			m_bAutoFlush;	//Whether to automatically refresh the file?
	bool			m_bModified;	//Whether the modified
	
//File Operation
public:
	//Re-initialization of the object
	void Reset(void);
	//Load profile, successful return 0, failed to return a value less than 0
	int LoadFromFile(const char* sFileName);
	//Refresh the current configuration items to file returns 0 on success, failure to return a value of 0 is involved in
	int FlushToFile(void);

//Regional methods of operation and configuration items
private:
	//According to the zone name, get the line number
	int GetSectionIndex(int nStartLine, const char* sSectionName);
	//According to the regional line number and configuration item name, get the line number where the configuration items
	int GetKeyIndex(int nSectionIndex, const char* sKeyName);
public:
	//Obtain the total number of regions
	int GetSectionCount(void);
	//Get zone name
	CString GetSectionName(int nIndex);
	//Obtain the total number of configuration items in the designated area
	int GetKeyCount(const char* sSectionName);
	//Obtain configuration item name
	CString GetKeyName(const char* sSectionName, int nIndex);
	//To delete a configuration item
	int DelKey(const char* sSectionName, const char* sKeyName);
	//Increase in one area, the return index value, failed to return a value less than 0
	int AddSection(const char* sSectionName);
	//To delete a region
	void DelSection(const char* sSectionName);
	
//Configuration item value method of operation
public:
	//Obtain configuration item value (string)
	CString GetString(const char* sSectionName, const char* sKeyName);
	//Obtain configuration item value (integer)
	int GetInt(const char* sSectionName, const char* sKeyName);
	//Obtain the value of configuration items (Boolean)
	bool GetBool(const char* sSectionName, const char* sKeyName);
	//Set the value of configuration items (string)
	void SetString(const char* sSectionName, const char* sKeyName, const char* sKeyValue);
	//Setting configuration item value (integer)
	void SetInt(const char* sSectionName, const char* sKeyName, int nKeyValue);
	//Set the value of the configuration items (Boolean)
	void SetBool(const char* sSectionName, const char* sKeyName, bool bKeyValue);
};

#endif
