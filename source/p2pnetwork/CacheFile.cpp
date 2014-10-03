#include "StdAfx.h"
#include ".\cachefile.h"

CCacheBlock::CCacheBlock(void) :
m_dwLastVisit(GetTickCount())
{
}

CCacheBlock::~CCacheBlock(void)
{
}

//------------------------------------------------

CCacheFile::CCacheFile(void)
{
}

CCacheFile::~CCacheFile(void)
{
	map<CCacheBlock *, CCacheBlock *>::iterator it = m_Blocks.begin();
	while ( it != m_Blocks.end() )
	{
		delete it->second;
		it = m_Blocks.erase(it);
	}
}

void CCacheFile::DeleteOverTimeBlock()
{
	DWORD dwLastVisitTime = GetTickCount();

	if ( m_Blocks.size() > RESERVE_BLOCK_NUM )
	{
		CCacheBlock *pDelBlock = NULL;
		map<CCacheBlock *, CCacheBlock *>::iterator it = m_Blocks.begin();
		while ( it != m_Blocks.end() )
		{
			if ( it->second->m_dwLastVisit < dwLastVisitTime)
			{
				dwLastVisitTime = it->second->m_dwLastVisit;
				pDelBlock = it->second;
			}
			it ++;
		}

		if ( pDelBlock )
		{
			it = m_Blocks.find( pDelBlock);
			if ( it != m_Blocks.end())
			{
				m_Blocks.erase( it);

				// Intermittent recording a log
				static DWORD WINAPI dwTempTime = GetTickCount();
				if ( dwTempTime + 5000 < GetTickCount() )
				{
					CKLog::WriteLog( LOG_TYPE_DEBUG, "Delete the cache block, the starting point:%u, last access time difference:%u", 
						pDelBlock->m_dwStartPos, GetTickCount() - pDelBlock->m_dwLastVisit);
					dwTempTime = GetTickCount();
				}

				delete pDelBlock;
			}
		}
	}
}

void CCacheFile::PushBlock( DWORD dwStartPos, char* pBuffer, DWORD dwLen)
{
	if ( BLOCK_LENGTH == dwLen )
	{
		// Remove reserved blocks beyond
		DeleteOverTimeBlock();

		CCacheBlock* pBlock = new CCacheBlock();
		if ( pBlock)
		{
			pBlock->m_dwStartPos = dwStartPos;
			memcpy( pBlock->m_szData, pBuffer, BLOCK_LENGTH);
			m_Blocks[pBlock] = pBlock;
		}
	}
}

DWORD CCacheFile::GetData( DWORD dwStartPos, char* pBuffer, DWORD dwLen)
{
	map<CCacheBlock *, CCacheBlock *>::iterator it = m_Blocks.begin();
	while ( it != m_Blocks.end() )
	{
		if ( it->second->m_dwStartPos <= dwStartPos && 
			(dwStartPos + dwLen) <= (it->second->m_dwStartPos + BLOCK_LENGTH) )
		{
			it->second->m_dwLastVisit = GetTickCount();
			DWORD dwPos = dwStartPos - it->second->m_dwStartPos;
			memcpy( pBuffer, it->second->m_szData + dwPos, dwLen);

			// Intermittent recording a log
			static DWORD WINAPI dwTempTime = GetTickCount();
			if ( dwTempTime + 5000 < GetTickCount() )
			{
				CKLog::WriteLog( LOG_TYPE_DEBUG, "Read from the cache, the absolute starting point:%u, the relative starting point:%u, read length:%u, chunks starting point:%u", 
					dwStartPos, dwPos, dwLen, it->second->m_dwStartPos);
				dwTempTime = GetTickCount();
			}

			return dwLen;
		}
		it ++;
	}

	return 0;
}

