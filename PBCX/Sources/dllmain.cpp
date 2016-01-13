// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

// {{{ @leaks: includes for memory leaks detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
/// }}}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	// {{{ @leaks:
	// Create file for leak reports
	HANDLE hLogFile = CreateFile(L"C:\\__PBS\\__LeaksDetectionReport.txt",
		GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			// {{{ @leaks:
			// Turn on debugging for memory leaks. This is automatically turned off when the build is Release.
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
			_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_WARN, hLogFile);
			_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_ERROR, hLogFile);
			_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_ASSERT, hLogFile);
			// }}}
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			// {{{ @leaks: Close file
			//CloseHandle(hLogFile);
			// }}}
			break;
	}
	return TRUE;
}

