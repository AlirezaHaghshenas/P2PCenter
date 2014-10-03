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
#include <string.h>

#define TCP_MAX_BUFFER_LENGTH 8192
#define UDP_MAX_BUFFER_LENGTH 1024
#define ROOM_PACKET_MAX_LEN   733
#define UDP_HEARTBEAT_INTERVAL 10000 // UDP Heartbeat interval 10 seconds
#define TCP_HEARTBEAT_INTERVAL 10000 // TCP Heartbeat interval 10 seconds
#define SERVER_VERSION "08.01.10.001"
#define CLIENT_VERSION "08.01.10.001"
#define PROTOCOL_VERSION '1001'

//source peer type define for PEERINFO::ucSource
#define PEER_TYPE_K8_GENERAL	'0'			//Ordinary K8 protocol client
#define PEER_TYPE_K8_SOURCE		'1'			//K8 protocol source, has all the blocks
#define PEER_TYPE_HTTP			'2'			//HTTP protocol, it should have all the blocks
#define PEER_TYPE_FTP			'3'			//FTP protocol, should have all the blocks
#define PEER_TYPE_BITTORRENT	'4'			//Bittorrent protocol source, with part of the block
#define PEER_TYPE_EDONKEY		'5'			//eDonkey protocol (emule), with part of the block

#pragma pack(push)
#pragma pack(1)
struct PEERINFO {
	unsigned long   ulID;
	unsigned long   ulExternalIP;
	unsigned short  usExternalUDPPort;
	unsigned short  usExternalTCPPort;
	unsigned long   ulLocalIP;
	unsigned short  usLocalUDPPort;
	unsigned short  usLocalTCPPort;
	unsigned char   ucSource;
	PEERINFO()
	{
		memset( this, 0, sizeof(PEERINFO) );
	}
};
#pragma pack(pop)

typedef enum P2S_CMD_TYPE
{
	// UDP DEFINE 
	P2S_CMD_SHOOTHOLE = 0x00001000,
	P2S_CMD_SHOOTHOLE_RET,
	P2S_CMD_UDP_HEARTBEAT,

	// TCP DEFINE
	P2S_CMD_CONNECT = 0x00002000,
	P2S_CMD_CONNECT_RET,

	P2S_CMD_GETGROUPS,
	P2S_CMD_GETGROUPS_RET,

	P2S_CMD_GETNODES,			// Node, file,
	P2S_CMD_GETNODES_RET,

	P2S_CMD_LOGIN_CHANNEL,		// Into the channel,
	P2S_CMD_LOGIN_CHANNEL_RET,

	P2S_CMD_LOGOUT_CHANNEL,		// Left channel,
	P2S_CMD_LOGOUT_CHANNEL_RET,

	P2S_CMD_GETPEERS,
	P2S_CMD_GETPEERS_RET,

	P2S_CMD_PEERLOGIN,  //--
	P2S_CMD_PEERLOGOUT, //--

	P2S_CMD_REQSHOOTTO,
	P2S_CMD_REQSHOOTTO_RET,

	P2S_CMD_SHOOTARRIVED,//--

	P2S_CMD_TCP_HEARTBEAT,		// TCP maintain links

	P2S_CMD_CLOSE,
	P2S_CMD_CLOSE_RET,

	P2S_CMD_ROOM_CREATE = 0x00003000,
	P2S_CMD_ROOM_CREATE_RET,
	P2S_CMD_ROOM_LOGIN,
	P2S_CMD_ROOM_LOGIN_RET,
	P2S_CMD_ROOM_LOGIN_NTF,
	P2S_CMD_ROOM_LOGOUT,
	P2S_CMD_ROOM_LOGOUT_RET,
	P2S_CMD_ROOM_LOGOUT_NTF, // notify
	P2S_CMD_ROOM_DELETE,
	P2S_CMD_ROOM_DELETE_RET,
	P2S_CMD_ROOM_MODIFY,
	P2S_CMD_ROOM_MODIFY_RET,
	P2S_CMD_ROOM_POST_DATA,
	P2S_CMD_ROOM_POST_DATA_RET,
	P2S_CMD_ROOM_POST_DATA_BRD,
	P2S_CMD_ROOM_GET_DATA,
	P2S_CMD_ROOM_GET_DATA_RET,
	P2S_CMD_ROOM_CLOSE,
	P2S_CMD_ROOM_CLOSE_RET,

	// monitor
	P2S_CMD_MONITOR_TRANSDATA
};
