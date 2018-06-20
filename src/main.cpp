#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{

	if (reason == DLL_PROCESS_ATTACH)
	{
	}
	else if (reason == DLL_PROCESS_DETACH)
	{
	}

	return 1;
}
