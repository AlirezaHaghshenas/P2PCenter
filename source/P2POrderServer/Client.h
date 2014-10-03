#pragma once

#include "p2sdefine.h"
#include "P2SCommand.h"

class CClient
{
public:
	CClient(void);
	virtual ~CClient(void);

	bool IsCanWork();

	PEERINFO m_peerInfo;
	// Holes have been received UDP packet
	bool m_bUdpAvail;
	// Connection packet has been received, the corresponding signaling P2S_CMD_CONNECT
	bool m_bConnAvail;
	// Random SESSION, unlike SOCKET Session
	int m_nSessionID;
	// socket ID
	unsigned long m_ulSocketID;
};
