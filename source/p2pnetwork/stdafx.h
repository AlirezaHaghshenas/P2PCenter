// stdafx.h : Standard include file system contains files£¬
// Common but rarely change or project specific include files
//

#pragma once


#define WIN32_LEAN_AND_MEAN		// From Windows Head rarely used to exclude data
// Windows The header file:
#include <windows.h>

#include <map>
#include <string>
#include <list>
using namespace std;

#include <atlbase.h>
#include <atlapp.h>
#include <atlmisc.h>

#include <assert.h>

#include "log/KLog.h"
#include "p2pdefine.h"
#include "p2sdefine.h"

#include "thread/KThread.h"
#include "misc/KPtrList.h"
#include "misc/KPtrMap.h"
#include "network/KSocket.h"

#include "ip2pnetwork.h"

#include "TcpClient.h"
#pragma comment(lib, "TcpClient.lib")
#pragma comment(lib, "WS2_32.lib")

#include "P2SCommand.h"
#include "P2PCommand.h"

#include "P2PNetwork.h"
extern CP2PNetwork* g_pNetwork;

// TODO: Additional header files referenced herein procedural requirements
