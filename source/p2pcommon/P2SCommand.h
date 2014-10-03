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

#include "basecommand.h"

namespace P2S_COMMAND
{
	//------------------------------------------------------------------------
	class CP2SCommandQuery
	{
	public:
		static string CommandString( unsigned int unCommand );
	};
	//------------------------------------------------------------------------
	class CCommandFactory
	{
	public:
		static CBaseCommand* CreateConnectCmd( string sUsername, string sPassword, int nLocalIP, short sLocalUdpPort, short sLocalTcpPort );
		static CBaseCommand* CreateGetPeersCmd( int nUserID, int nSessionID, string sChannelID, bool bSource );
		static CBaseCommand* CreateLoginChannelCmd( int nUserID, int nSessionID, string sNodeName,
			string sChannelID, bool bSource, string sFilePath, string sFileName, string sFileSize );
		static CBaseCommand* CreateLoginChannelRetCmd( int nUserID, int nSessionID, string sNodeName,
			string sChannelID, bool bSource, string sFilePath, string sFileName, string sFileSize );
		static CBaseCommand* CreateLogoutChannelCmd( int nUserID, int nSessionID, string sChannelID );
		static CBaseCommand* CreateLogoutChannelRetCmd( int nUserID, int nSessionID, string sChannelID );
		static CBaseCommand* CreateUdpHeartbeatCmd( int nUserID, int nSessionID, string sAuthStr );
		static CBaseCommand* CreateTcpHeartbeatCmd( int nUserID, int nSessionID, string sAuthStr );
		static CBaseCommand* CreateReqShootToCmd( int nUserID, int nSessionID, int nTargetUserID );
		static CBaseCommand* CreateReqShootToRetCmd( int nUserID, int nSessionID, int nTargetUserID );
		static CBaseCommand* CreateReqShootArritedCmd( int nUserID, int nSessionID, const PEERINFO& targetPeerinfo);
	};
	//------------------------------------------------------------------------ Holes to UDP packets sent by the server
	class CCmdShootHole : public CBaseCommand
	{
	public:
		CCmdShootHole();
		virtual ~CCmdShootHole(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};

	class CCmdShootHoleRet : public CBaseCommand
	{
	public:
		CCmdShootHoleRet();
		virtual ~CCmdShootHoleRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------
	class CCmdConnect : public CBaseCommand
	{
	public:
		CCmdConnect();
		virtual ~CCmdConnect(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		string m_sUsername;
		string m_sPassword;
		int	   m_nLocalIP;
		short  m_sLocalUdpPort;
		short  m_sLocalTcpPort;
	};

	class CCmdConnectRet : public CBaseCommand
	{
	public:
		CCmdConnectRet();
		virtual ~CCmdConnectRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nResult; // Login result, 0 for success
	};
	//------------------------------------------------------------------------
	class CCmdGetGroups : public CBaseCommand
	{
	public:
		CCmdGetGroups();
		virtual ~CCmdGetGroups(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};

	class CCmdGetGroupsRet : public CBaseCommand
	{
	public:
		CCmdGetGroupsRet();
		virtual ~CCmdGetGroupsRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------
	class CCmdGetNodes : public CBaseCommand
	{
	public:
		CCmdGetNodes();
		virtual ~CCmdGetNodes(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};

	class CCmdGetNodesRet : public CBaseCommand
	{
	public:
		CCmdGetNodesRet();
		virtual ~CCmdGetNodesRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------
	class CCmdLoginChannel : public CBaseCommand
	{
	public:
		CCmdLoginChannel();
		virtual ~CCmdLoginChannel(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sNodeName;
		string m_sChannelID;
		char   m_cSource;	//'0', '1'
		string m_sFilePath;
		string m_sFileName;
		string m_sFileSize;
	};

	class CCmdLoginChannelRet : public CBaseCommand
	{
	public:
		CCmdLoginChannelRet();
		virtual ~CCmdLoginChannelRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sNodeName;
		string m_sChannelID;
		char   m_cSource;	//'0', '1'
		string m_sFilePath;
		string m_sFileName;
		string m_sFileSize;
	};
	//------------------------------------------------------------------------
	class CCmdLogoutChannel : public CBaseCommand
	{
	public:
		CCmdLogoutChannel();
		virtual ~CCmdLogoutChannel(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
	};

	class CCmdLogoutChannelRet : public CBaseCommand
	{
	public:
		CCmdLogoutChannelRet();
		virtual ~CCmdLogoutChannelRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
	};
	//------------------------------------------------------------------------
	class CCmdGetPeers : public CBaseCommand
	{
	public:
		CCmdGetPeers();
		virtual ~CCmdGetPeers(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
		char m_cSource; // Whether he is the source '0' 'a' and is not
	};

	class CCmdGetPeersRet : public CBaseCommand
	{
	public:
		CCmdGetPeersRet();
		virtual ~CCmdGetPeersRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
		int m_nPeerCount;
		list<PEERINFO> m_listPeers;
	};

	class CCmdPeerLogin : public CBaseCommand
	{
	public:
		CCmdPeerLogin();
		virtual ~CCmdPeerLogin(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
		int m_nPeerCount;
		list<PEERINFO> m_listPeers;
	};

	class CCmdPeerLogout : public CBaseCommand
	{
	public:
		CCmdPeerLogout();
		virtual ~CCmdPeerLogout(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		string m_sChannelID;
		int m_nPeerCount;
		list<PEERINFO> m_listPeers;
	};
	//------------------------------------------------------------------------ Server TCP port to burrow package sent via TCP conveyed to the target users to their handshake
	class CCmdReqShootTo : public CBaseCommand
	{
	public:
		CCmdReqShootTo();
		virtual ~CCmdReqShootTo(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nTargetUserID;
	};

	class CCmdReqShootToRet : public CBaseCommand
	{
	public:
		CCmdReqShootToRet();
		virtual ~CCmdReqShootToRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nTargetUserID;
	};

	class CCmdShootArrived : public CBaseCommand
	{
	public:
		CCmdShootArrived();
		virtual ~CCmdShootArrived(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		PEERINFO m_peerinfoSource;	// Source user peerinfo, after receiving this package, as previously did not establish a connection with the user, namely the user to send handshake packets
	};
	//------------------------------------------------------------------------
	class CCmdTcpHeartbeat : public CBaseCommand
	{
	public:
		CCmdTcpHeartbeat();
		virtual ~CCmdTcpHeartbeat(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------
	class CCmdClose : public CBaseCommand
	{
	public:
		CCmdClose();
		virtual ~CCmdClose(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};

	class CCmdCloseRet : public CBaseCommand
	{
	public:
		CCmdCloseRet();
		virtual ~CCmdCloseRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------
	class CCmdUdpHeartbeat : public CBaseCommand
	{
	public:
		CCmdUdpHeartbeat();
		virtual ~CCmdUdpHeartbeat(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
	};
	//------------------------------------------------------------------------




	//------------------------------------------------------------------------
	class CCmdRoomCreate : public CBaseCommand
	{
	public:
		CCmdRoomCreate();
		virtual ~CCmdRoomCreate(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		unsigned char m_ucMaxPersons;
		int m_nKind;
		string m_sName;
		string m_sPassword;
	};

	class CCmdRoomCreateRet : public CBaseCommand
	{
	public:
		CCmdRoomCreateRet();
		virtual ~CCmdRoomCreateRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		unsigned char m_ucMaxPersons;
		int m_nKind;
		string m_sName;
		int m_nID;
	};
	//------------------------------------------------------------------------
	class CCmdRoomLogin : public CBaseCommand
	{
	public:
		CCmdRoomLogin();
		virtual ~CCmdRoomLogin(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
	};

	class CCmdRoomLoginRet : public CBaseCommand
	{
	public:
		CCmdRoomLoginRet();
		virtual ~CCmdRoomLoginRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nMasterID; 
		int m_nRet;		// 0 == succeed. -1 == failed. -2 == full, -3 == password error, -4 == blacklist
		unsigned char m_ucIndex;	// self in room's index 0-->(MaxPersons-1)
		unsigned char m_ucMaxPersons;
		unsigned char m_ucCurPersons; // include self
	};

	class CCmdRoomLoginNtf : public CBaseCommand
	{
	public:
		CCmdRoomLoginNtf();
		virtual ~CCmdRoomLoginNtf(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nMasterID; 
		unsigned char m_ucMaxPersons;
		unsigned char m_ucCurPersons;
		map<unsigned char, PEERINFO> m_mapPersons; // unsigned char == index
	};
	//------------------------------------------------------------------------
	class CCmdRoomLogout : public CBaseCommand
	{
	public:
		CCmdRoomLogout();
		virtual ~CCmdRoomLogout(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
	};

	class CCmdRoomLogoutRet : public CBaseCommand
	{
	public:
		CCmdRoomLogoutRet();
		virtual ~CCmdRoomLogoutRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nRet;		// 0 == succeed. -1 == failed.
		unsigned char m_ucIndex;	// self in room's index 0-->(MaxPersons-1)
	};

	class CCmdRoomLogoutNtf : public CBaseCommand
	{
	public:
		CCmdRoomLogoutNtf();
		virtual ~CCmdRoomLogoutNtf(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nPeerID;
		unsigned char m_ucIndex;
	};
	//------------------------------------------------------------------------
	class CCmdRoomDelete : public CBaseCommand
	{
	public:
		CCmdRoomDelete();
		virtual ~CCmdRoomDelete(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
	};

	class CCmdRoomDeleteRet : public CBaseCommand
	{
	public:
		CCmdRoomDeleteRet();
		virtual ~CCmdRoomDeleteRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nRet;		// 0 == succeed. -1 == failed.
	};
	//------------------------------------------------------------------------ room master option
	class CCmdRoomModify : public CBaseCommand
	{
	public:
		CCmdRoomModify();
		virtual ~CCmdRoomModify(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nOldKind;
		int m_nNewKind;
		string m_sName;
	};

	class CCmdRoomModifyRet : public CBaseCommand
	{
	public:
		CCmdRoomModifyRet();
		virtual ~CCmdRoomModifyRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nOldKind;
		int m_nNewKind;
		string m_sName;
		int m_nRet;		// 0 == succeed. -1 == failed.
	};
	//------------------------------------------------------------------------
	class CCmdRoomPostData : public CBaseCommand
	{
	public:
		CCmdRoomPostData();
		virtual ~CCmdRoomPostData(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nDataNum; // No.
		unsigned short m_usDataLen;
		char m_szData[ROOM_PACKET_MAX_LEN];
	};

	class CCmdRoomPostDataRet : public CBaseCommand
	{
	public:
		CCmdRoomPostDataRet();
		virtual ~CCmdRoomPostDataRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nDataNum; // No.
		unsigned short m_usDataLen;
	};

	class CCmdRoomPostDataBrd : public CBaseCommand
	{
	public:
		CCmdRoomPostDataBrd();
		virtual ~CCmdRoomPostDataBrd(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nDataNum; // No.
		unsigned char m_ucBroadcastNum; // listBroadcastIndex size
		list<unsigned char> m_listBroadcastIndex; // user index in room
		unsigned short m_usDataLen;
		char m_szData[ROOM_PACKET_MAX_LEN];
	};
	//------------------------------------------------------------------------
	class CCmdRoomGetData: public CBaseCommand
	{
	public:
		CCmdRoomGetData();
		virtual ~CCmdRoomGetData(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nDataNum;
		int m_nPriority; // 0 Maximum
	};

	class CCmdRoomGetDataRet : public CBaseCommand
	{
	public:
		CCmdRoomGetDataRet();
		virtual ~CCmdRoomGetDataRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nDataNum; // No.
		unsigned short m_usDataLen;
		char m_szData[ROOM_PACKET_MAX_LEN];
	};
	//------------------------------------------------------------------------
	class CCmdRoomClose: public CBaseCommand
	{
	public:
		CCmdRoomClose();
		virtual ~CCmdRoomClose(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
	};

	class CCmdRoomCloseRet : public CBaseCommand
	{
	public:
		CCmdRoomCloseRet();
		virtual ~CCmdRoomCloseRet(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		int m_nRet;	// 0: Normal closed success, -1: No permission -2: room does not exist -3: Lock
	};
	//------------------------------------------------------------------------

	class CCmdMonitorTransdata : public CBaseCommand
	{
	public:
		CCmdMonitorTransdata();
		virtual ~CCmdMonitorTransdata(void);

		virtual int Create( char* pBuffer, int& nLen ); 
		virtual int Parse( char* pBuffer, int nLen );

	public:
		int m_nUserID;
		int m_nSessionID;
		int m_nID;
		char m_cRemoveAllFlag;		// Remove all signs, such as 1, delete all monitoring, 0 == add
		char m_cTransType;			// Transmission direction, a == income, 2 == hair
		char m_cMonitorType;		// Monitor Type£º1 == P2S TCP£¬ 2 == P2S UDP, 3 == P2P TCP, 4 = P2P UDP
		char m_cTransWeight;		// The amount of transmitted data: 1 == bag all the data, only 2 = the CMD ID
		char m_cSendInterval;		// Monitor sends the minimum interval, accurate to the millisecond
		int m_nDstIP;				// Target UDP IP
		unsigned short m_usDstPort;	// Target UDP PORT
	};
	//------------------------------------------------------------------------


};

