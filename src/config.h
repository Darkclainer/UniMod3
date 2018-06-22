#ifndef CONFIG_23_07_18_H
#define CONFIG_23_07_18_H

#include <string>
#include <map>
#include "sol/forward.hpp"

class Config
{
public:
	Config(sol::state& lua, const std::string& fileName);

	using Options = std::map<std::string, std::string>;
private:
	Options options;
	
};

#endif//CONFIG_23_07_18_H
