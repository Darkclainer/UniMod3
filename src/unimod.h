#ifndef UNIMOD_23_07_18_H
#define UNIMOD_23_07_18_H

#include "sol.hpp"

#include "config.h"

class UniMod
{
public:
	static UniMod* getInstance();

public:
	sol::state lua;

private:
	static UniMod* instance;
	UniMod();

	Config config;

};

#endif//UNIMOD_23_07_18_H
