#ifndef CONFIG_23_07_18_H
#define CONFIG_23_07_18_H

#include <string>
#include <map>
#include "sol/forward.hpp"

class Config
{
public:
	Config(sol::state& lua, const std::string& fileName);

	decltype(auto) getOption(const std::string& optionName)
	{
		return options[optionName];
	}
	
	template<class T>
	sol::optional<T> getOption(const std::string& optionName)
	{
		return options[optionName];
	}
private:
	void setDefaultOptions(sol::table& options);

private:
	sol::environment options;
};

#endif//CONFIG_23_07_18_H
