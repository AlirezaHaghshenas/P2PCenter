#pragma once

#include "P2PPacket.h"

// Block index starts from 0
class CP2PPacketMgr :
	public CKPtrMap<DWORD, CP2PPacket>
{
public:
	CP2PPacketMgr(void);
	virtual ~CP2PPacketMgr(void);
	
	// Read the file fragments
	bool ReadSegment( DWORD dwStartPos, char* pBuffer, DWORD& dwLength );
	// Block delete closed interval [dwStartBlock, dwEndBlock] outside
	void RemoveBlock( DWORD dwStartBlock, DWORD dwEndBlock );
	// Receive a new package
	bool PacketArrived( DWORD dwBlockIndex, char* pBuffer );
	// Request some blocks
	void InsertShouldBlock( DWORD dwStartBlock, DWORD dwBlockNum );
	// Delete all unused requesting block number
	void ClearShouldBlock();
	// Timeout block status update in order to request re-
	// Timing calls, time not more than one second, built Protocol 100us
	void UpdateTimeOutStatus( DWORD dwTimeUsec = UDP_REQUEST_TIMEOUT );
	// After calling this function immediately initiate a request in this function in the updated timestamp, such as false, then no request block
	bool GetShouldBlock( DWORD& dwStart, DWORD& dwEnd );
	// MAP in the block status updates
	void UpdatePacketStatus( const map<DWORD, DWORD>& mapRequests, PACKET_STATUS status);

	// Obtain existing block, complete block
	bool GetExistBlockAreas( map<DWORD, DWORD>& mapAreas );
	bool GetExistBlockList( list<DWORD>& listBlock, DWORD dwStartBlock, DWORD dwEndBlock );
};
