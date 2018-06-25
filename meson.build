project('UniMod3', 'cpp',
	license: 'GPL3',
	version: '0.1',
	default_options: ['cpp_std=c++11', 'default_library=static']
)

compiler = meson.get_compiler('cpp')
if compiler.get_id() != 'msvc'
	error('Regard to platform specific project purpose only msvc compiler supported!')
endif

# build dll that load UniMod3.dll
UniModLoader = subproject('UniModLoader')
UniModLoader_lib = UniModLoader.get_variable('UniModLoader_lib')
UniModLoader_dep = UniModLoader.get_variable('UniModLoader_dep')

# get sol2 dependency
sol2_dep = dependency('sol2', 
	fallback: [ 'sol2', 'sol2_dep' ],
	static: true
)

src_raw = ['main.cpp', 'unimod.cpp', 'config.cpp']
src_prefix = 'src/'
src = []
foreach s : src_raw
	src += [src_prefix + s]
endforeach


UniMod3_lib = shared_library('UniMod3', 
	sources: src,
	dependencies: [sol2_dep]
)

# file to copy into Nox Dir
copied_files = [
	UniMod3_lib,#.full_path(),
	UniModLoader_lib,#.full_path(),
	meson.source_root() + '/lua_files/UniModConfig.lua'
]

# hack for copy dlls file to Nox Dir
nox_dir = get_option('nox_dir')
if nox_dir != ''
	filecopier = find_program('filecopier.py')
	command = [filecopier] + [nox_dir] + copied_files
	targetName = 'UniMod3_All'
	run_target(targetName,
		command : command
	)
	
	userConfigurationCreator = find_program('userConfigurationCreator.py')
	nox_exe = get_option('nox_exe')
	run_command(userConfigurationCreator, targetName, meson.build_root(), nox_dir, nox_exe)
endif
