#pragma once

#define BLOCK_LENGTH 64 *1024	// 64K
#define RESERVE_BLOCK_NUM	10  // Up to retain 10, more in accordance with the policy is removed

class CCacheBlock
{
public:
	CCacheBlock(void);
	virtual ~CCacheBlock(void);

public:
	DWORD m_dwStartPos;
	char  m_szData[BLOCK_LENGTH];
	DWORD m_dwLastVisit;
};

class CCacheFile
{
public:
	CCacheFile(void);
	virtual ~CCacheFile(void);
	void DeleteOverTimeBlock();
	void PushBlock( DWORD dwStartPos, char* pBuffer, DWORD dwLen);
	DWORD GetData(  DWORD dwStartPos, char* pBuffer, DWORD dwLen);	// noexist return 0;There is some lack of long return

protected:
	map<CCacheBlock *, CCacheBlock *> m_Blocks;
};
