#include "sol.hpp"

#include "unimod.h"

UniMod* UniMod::instance = nullptr;

UniMod* UniMod::getInstance()
{
	if (instance == nullptr)
	{
		instance = new UniMod();
	}
	return instance;
}
