#!/usr/local/bin/python3
import sys
from pathlib import Path
import shutil

partOfProjectName = sys.argv[1]

buildPath = Path(sys.argv[2])

noxPath = Path(sys.argv[3])
noxExePath = noxPath / sys.argv[4]
print('UURRAA!')
print(noxExePath)

userProject = buildPath / (partOfProjectName + '@run.vcxproj.user')

if userProject.exists() == False:
	userProject.touch()
	with open(userProject, 'w') as file:
		file.write(
'''<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <PropertyGroup>
    <LocalDebuggerCommand>{}</LocalDebuggerCommand>
    <LocalDebuggerCommandArguments>{}</LocalDebuggerCommandArguments>
    <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
  </PropertyGroup>
</Project>'''.format(str(noxExePath), str(noxPath)))
