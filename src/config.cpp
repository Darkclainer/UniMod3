#include "sol.hpp"
#include "config.h"

void Config::setDefaultOptions(sol::table& options)
{
	options.set(
		"DebugMode", false,
		"MultipleNoxInstances", false
	);
}
Config::Config(sol::state& lua, const std::string& fileName)
	:options(lua, sol::create)
{
	// set default options
	setDefaultOptions(options);

	// load and execute file with options table as environment
	sol::protected_function_result result = lua.safe_script_file(fileName, options, sol::load_mode::text);

	if (!result.valid())
		return; // ToDo: print error message!
}
