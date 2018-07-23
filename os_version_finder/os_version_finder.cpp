// os_version_finder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	OSVERSIONINFO osvi;
	BOOL bIsWindows7orLater = false;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

#if 0
	bIsWindows7orLater = 
		( (osvi.dwMajorVersion > 6) ||
		( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 1) ));
#else
	// ��ЩWIN7���Է��ص�minorversion==0�����ֻ�ж����汾��
	bIsWindows7orLater = (osvi.dwMajorVersion >= 6);
#endif

	printf("majorVersion=%d minorVersion=%d bIsWindows7orLater=%d\r\n", osvi.dwMajorVersion, osvi.dwMinorVersion, bIsWindows7orLater);

	if(bIsWindows7orLater)
	{
		printf("This computer is windows7 or later\r\n");
	}

	system ("pause");

	return 0;
}