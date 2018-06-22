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
UniModLoader = subproject('UniModLoader').get_variable('UniModLoader')

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


UniMod3 = shared_library('UniMod3', 
	sources: src,
	dependencies: [sol2_dep]
)

# hack for copy dlls file to Nox Dir
nox_dir = get_option('nox_dir')
if nox_dir != ''
	filecopier = find_program('filecopier.py')
	run_target('UniMod3_Copy',
		command : [filecopier, 
			nox_dir,
			UniMod3.full_path(), 
			UniModLoader.full_path()
		],
		depends: [UniModLoader, UniMod3]
	)

endif
