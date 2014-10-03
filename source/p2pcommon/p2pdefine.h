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

#pragma once

//Signalling between the client and the client's
typedef enum P2P_CMD_TYPE
{
	P2P_CMD_HANDSHAKE = 0x10001000,		// Handshake
	P2P_CMD_HANDSHAKE_RET,		
	P2P_CMD_GETBLOCK_AREA,				// Made with blocks
	P2P_CMD_GETBLOCK_AREA_RET,			// Made with block returns
	P2P_CMD_GETSEGMENT,					// Get file fragment
	P2P_CMD_GETSEGMENT_RET,				// Get file fragment returns
	P2P_CMD_STAT_UPLOAD,				// Discover the other upload capability
	P2P_CMD_STAT_UPLOAD_RET,			// Query returns the other upload capability
	P2P_CMD_HEARTBEAT,					// Heartbeat, maintain links
	P2P_CMD_CANCELSEGMENT,				// Block cancellation request
	P2P_CMD_CANCELSEGMENT_RET,			// Block cancellation request to return
	P2P_CMD_EXIT						// Unilateral exit
};

typedef __int64 QWORD;

#define UDP_PACKET_LENGTH 933
#define UDP_BUFFER_LENGTH 1024
// Request timeout unit (millisecond)
#define UDP_REQUEST_TIMEOUT 3000
#define P2P_QUERYBLOCK_INTERVAL 5000	  // Query block interval exists
#define P2P_MAX_GETSEGMENT_INTERVAL 10000 // Request single largest block within the range 10M
#define P2P_HEARTBEAT_INTERVAL      15000 // P2P heartbeat interval
#define P2P_TIMEREQUEST_MAX_NUM		64	  // The maximum number of blocks a single request to a single PEER
#define P2P_TIMESEND_MAX_NUM		64	  // PEER sent a single to a single maximum number of blocks

