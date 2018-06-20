project('unimodLoader', 'cpp',
	license: 'GPL3',
	version: '1.0'
)

# Test is compiler is mvsc compiler. 
compiler = meson.get_compiler('cpp')
if compiler.get_id() != 'msvc'
	error('Regard to platform specific project purpose only msvc compiler supported!')
endif

UniModLoader = shared_library('dinput', 
	sources: ['main.cpp'],
)

