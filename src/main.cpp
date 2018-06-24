#include <windows.h>
#include <exception>
#include "sol.hpp"

#include "unimod.h"

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
try
{

	if (reason == DLL_PROCESS_ATTACH)
	{
		UniMod* unimod = UniMod::getInstance();
	}
	else if (reason == DLL_PROCESS_DETACH)
	{
		UniMod* unimod = UniMod::getInstance();
		delete unimod;
	}

	return 1;
}
catch (std::exception& e)
{
	e.what();
}
catch (...)
{
}
