project('UniMod3', 'cpp',
	license: 'GPL3',
	version: '0.1',
	default_options: ['cpp_std=c++11']
)

compiler = meson.get_compiler('cpp')
if compiler.get_id() != 'msvc'
	error('Regard to platform specific project purpose only msvc compiler supported!')
endif

UniModLoader = subproject('UniModLoader').get_variable('UniModLoader')

src_raw = ['main.cpp']
src_prefix = 'src/'
src = []
foreach s : src_raw
	src += [src_prefix + s]
endforeach


UniMod3 = shared_library('UniMod3', 
	sources: src
)

# hack for copy Dll file to Nox Dir
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
