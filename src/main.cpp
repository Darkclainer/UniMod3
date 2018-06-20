#include <windows.h>
#include "sol.hpp"

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{

	if (reason == DLL_PROCESS_ATTACH)
	{
		sol::state lua;
		int x = 0;
		lua.set_function("beep", [&x] { ++x; });
		lua.script("beep()");
	}
	else if (reason == DLL_PROCESS_DETACH)
	{
	}

	return 1;
}
