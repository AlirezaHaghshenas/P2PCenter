// stdafx.h : Standard include file system contains files，
// Common but rarely change or project specific include files
//

#pragma once

#ifndef STRICT
#define STRICT
#endif

// If you must use the following specified platform before the platform, then modify the following definition.
// The latest information on the corresponding values ​​for different platforms, please refer to MSDN.
#ifndef WINVER				// Allows the use of specific to Windows 95 and Windows NT 4 or later versions of the function.
#define WINVER 0x0502//shervin 0x0400		// This change is targeted at Windows 98 And Windows 2000 Or suitable value later。
#endif

#ifndef _WIN32_WINNT		// Allows the use of specific Windows NT 4 Or later function。
#define _WIN32_WINNT 0x0502// shervin 0x0400	// This change is targeted at Windows 2000 Or suitable value later。
#endif						

#ifndef _WIN32_WINDOWS		// Allows the use of specific Windows 98 Or later function。
#define _WIN32_WINDOWS 0x0410 // This change is targeted at Windows Me Or suitable value later。
#endif

#ifndef _WIN32_IE			// Allows the use of specific IE 4.0 Or later function。
#define _WIN32_IE 0x0400	// Change this to the appropriate value for the in IE 5.0 or later。
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// Some CString constructors will be explicit

// Close ATL common security warning message is often overlooked for some hidden
#define _ATL_ALL_WARNINGS

#pragma warning( disable: 4267 )
#pragma warning( disable: 4244 )
#pragma warning( disable: 4018 )

#include "resource.h"
#include <stdio.h>
#include <atlbase.h>
#include <atlcom.h>

#include <tchar.h>
#include <winsock2.h>

#ifdef _DEBUG
#define DEBUG_NEW new
#endif

using namespace ATL;

//#define REQUEST_MAX_SIZE 5 * 1024 * 1024 // 5M
#define REQUEST_MAX_SIZE 2 * 1024 * 1024  // 1M
