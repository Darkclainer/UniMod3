#!/usr/local/bin/python3
import sys
import shutil

for i in range(2, len(sys.argv)):
	shutil.copy(sys.argv[i], sys.argv[1])

