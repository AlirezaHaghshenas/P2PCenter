#pragma once

typedef enum PACKET_STATUS
{
	PACKET_STATUS_NONE = 0,
	PACKET_STATUS_REQUESTED,
	PACKET_STATUS_ARRIVED
};

class CP2PPacket
{
public:
	CP2PPacket(void);
	virtual ~CP2PPacket(void);

	char* m_pBuffer;
	// Recent transmission request timestamp
	DWORD m_dwLastRequest;
	// Is not a valid, i.e., whether the data has been made
	PACKET_STATUS  m_packetStatus;
};
