#include "sol.hpp"
#include "config.h"

static void setDefaultOptions(Config::Options& options)
{
	static Config::Options defaultOptions = {
		{"DebugMode", "false"},
		{"MultipleNoxInstances", "false"}
	};
	options = defaultOptions;
}
Config::Config(sol::state& lua, const std::string& fileName)
{
	// set default options
	setDefaultOptions(options);

	// set temporary environment


	// load and execute file
	// get options from temporary environment
	auto loadResult = lua.load_file(fileName, sol::load_mode::text);
}
