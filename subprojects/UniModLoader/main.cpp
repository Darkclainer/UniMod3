#include <windows.h>

#pragma comment(linker, "/export:DirectInputCreateA=C:\\Windows\\System32\\dinput.DirectInputCreateA,@1")

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	static HINSTANCE hUniMod = 0;

	if (reason == DLL_PROCESS_ATTACH)
	{
		hUniMod = LoadLibrary("UniMod3.dll");
	}
	else if (reason == DLL_PROCESS_DETACH)
	{
		if (hUniMod != 0) 
			FreeLibrary(hUniMod);
	}

	return 1;
}
