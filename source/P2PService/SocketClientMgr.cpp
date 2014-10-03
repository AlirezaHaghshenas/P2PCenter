#include "StdAfx.h"
#include ".\socketclientmgr.h"

CSocketClientMgr::CSocketClientMgr(void) : 
m_pP2PNetwork(NULL),
m_bConnected(false)
{
}

CSocketClientMgr::~CSocketClientMgr(void)
{
	Release();
}

int CSocketClientMgr::OnConnect()//shervin added int
{
	m_bConnected = true;
	return 0;////shervin
}

int CSocketClientMgr::OnDisConnect()//shervin added int
{
	m_bConnected = false;
	return 0;//shervin
}

bool CSocketClientMgr::Connect()
{
	m_pP2PNetwork = CreateP2PNetwork();
	if ( !m_pP2PNetwork )
		return false;

	if ( !m_pP2PNetwork->InitModule( this ) )
		return false;

	return true;
}

void CSocketClientMgr::Release()
{
	if ( m_pP2PNetwork )
	{
		m_pP2PNetwork->ReleaseModule();
		m_pP2PNetwork = NULL;
	}
}


