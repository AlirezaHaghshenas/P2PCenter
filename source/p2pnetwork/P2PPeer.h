#pragma once

typedef enum CONNNECT_STATUS
{
	CONNNECT_STATUS_NONE = 0,
	CONNNECT_STATUS_HANDSHAKING,
	CONNNECT_STATUS_CONNECTED,
	CONNNECT_STATUS_DISCONNECTED
};

struct ST_TRANS_STAT {
	DWORD dwTime;
	DWORD dwBytes;
	ST_TRANS_STAT()
	{
		dwTime = GetTickCount();
		dwBytes = UDP_PACKET_LENGTH;
	}
};

// Speed ​​statistics interval, units, second
#define SPEED_STAT_INTERVAL 10

class CP2PPeer
{
public:
	CP2PPeer(void);
	virtual ~CP2PPeer(void);

	virtual bool IsHaveBlock( int nBlockNum );

	void CalcRequestBlock( DWORD dwBlock );	// The direction of the other party has requested block
	void CalcRecvBlock( DWORD dwBlock );	// Party requested block has been received
	double HealthRate();

	void CalcGetBlock( DWORD dwBlock );		// Right direction has been requested block party
	void CalcSendBlock( DWORD dwBlock );	// The direction of the other block has been sent
	double ReturnRate();

	PEERINFO m_peerInfo;
	map<DWORD, DWORD> m_mapBlockAreas;
	CONNNECT_STATUS m_connStatus;
	map<DWORD, DWORD> m_mapNeedBlocks;  // Here's block numbers are to be sent to the PEER The，second Reservations
	DWORD    m_dwUploadBytes;			// Upload capacity, average upload BYTE byte units within ten seconds / second
	DWORD    m_dwRecvBytes;				// Local statistics upload capability, the average received byte units within ten seconds BYTE / sec, which is a rating PEER
	DWORD    m_dwLastHeartbeatTime;		// Send heartbeat last time

	DWORD    m_dwRequestBlocks;			// The number of blocks requested
	DWORD    m_dwReceiveBlocks;			// The number of blocks received
	DWORD    m_dwGetBlocks;				// The requested number of blocks
	DWORD    m_dwSendBlocks;			// The number of blocks sent
	list<ST_TRANS_STAT> m_listUploads;	// Upload byte list first = time
	list<ST_TRANS_STAT> m_listReceives;	// List of bytes received
};
