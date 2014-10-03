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
#define WINVER 0x0502//shervin 0x0400		// Change this to the appropriate value for the Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allows the use of specific to Windows NT 4 or later versions of the function.
#define _WIN32_WINNT 0x0502//shervin0x0400	// Change this to the appropriate value for 2000 or later on Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allows the use of specific to Windows 98 or later version.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value for the in Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allows the use of specific IE 4.0 or later function.
#define _WIN32_IE 0x0400	// Change this to the appropriate value for IE 5.0 or later on.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// Some CString constructors will be explicit

// Close ATL common security warning message is often overlooked for some hidden
#define _ATL_ALL_WARNINGS

#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>


using namespace ATL;
