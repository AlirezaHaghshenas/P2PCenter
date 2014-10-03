#pragma once

#include "network/KSocket.h"
#include "misc/KDataBuffer.h"

class CTransMonitor
{
public:
	CTransMonitor(void);
	virtual ~CTransMonitor(void);

	bool PushBuffer( const char* szData, int nLen);
	void SendData();
	void ClearData();

public:
	char m_cTransType;			// Transmission direction, a == income, 2 == hair
	char m_cMonitorType;		// Monitor Type£º1 == P2S TCP£¬ 2 == P2S UDP, 3 == P2P TCP, 4 = P2P UDP
	char m_cTransWeight;		// The amount of transmitted data: 1 == bag all the data, 2 == only CMD ID, currently ignored, send all package contents
	char m_cSendInterval;		// Monitor sends the minimum interval, accurate to seconds¡£
	int m_nDstIP;				// The goal UDP IP
	unsigned short m_usDstPort;	// The goal UDP PORT

private:
	CKUdpSocket m_udpSocket;
	CKPtrList<CKDataBuffer> m_listData; 
};
