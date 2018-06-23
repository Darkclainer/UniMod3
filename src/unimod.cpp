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

UniMod::UniMod()
	:lua(), config(lua, "UniModConfig.lua")
{

	auto c = config.getOption<bool>("SomeRandomOption");
	if (c)
	{
	
	}
	else
	{

	}
}
