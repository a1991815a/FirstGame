// stdafx.h : 标准系统包含文件的包含文件，
#ifndef __STDAFX__
#define __STDAFX__

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include "header.h"
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <conio.h>

#ifdef _DEBUG
#include <windows.h>

#define  CCASSERT(_Expression, _log) (void)( (!!(_Expression)) || \
(_CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__,0,_log), 0) );

#define DEBUG_STRING(condition,format,...)											\
	if(condition){																	\
		wchar_t debug_out[256];														\
		wsprintf(debug_out, _T(format)##_T("\r\n"), __VA_ARGS__);					\
		OutputDebugStringW(debug_out);}	



#else
#define DEBUG_STRING(condition,format,...) 
#define  CCASSERT(_Expression, _log) 
#endif // _DEBUG


using namespace std;

#endif
