# UniMod3
Use Lua scripts in the Nox game!

## How to build
There is little sence to build project with compiler other than Visual Studio compiler, because UniMod3 is for the Nox game - Windows only application. I don't test, but possible that other compiler will be ABI incompatible with Nox. 

Project use [Meson](http://mesonbuild.com/index.html) build system. It allows to use different version of MVS and facilitates project dependency. But there are and cons too.

To build project you need:
1. Installed Meson (you read about Meson installation [here](http://mesonbuild.com/Getting-meson.html). It's very easy. Seriously.)
2. Installed Visual Studio with compiller that support C++11 (I tested vs2015 and vs2017).

Open your Developer Command Line (Prompt?) and write:
```
meson.py UniMod3GitDir UniMod3BuildDir --backend vs2017 --Dnox_dir=D:/WhereYouNoxIs
```
Option nox_dir allows you to copy all neccesarry UniMod3 files to your Nox by rebuilding UniMod3_copy target.

After that meson generate Visual Studio files for UniMod3.

