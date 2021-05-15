
import os
import sys
import argparse
import subprocess

#### dynamic naming of executable###############
# executable_name = ""                         #
# for i in range(len(name) - 1):               #
#     executable_name += (name[i] + ".")       #
# executable_name += "exe"                     #
################################################

executable_name = "out.exe"
li = ["go", "build", "-o", executable_name, sys.argv[1]]
err = subprocess.run(li, stderr=subprocess.PIPE)
if len(err.stderr.decode('utf-8')) != 0:
    print(err.stderr.decode('utf-8'))
    print("'\n\nBUILD FAILED\n\n")
    sys.exit()
file = open(sys.argv[1], 'a', buffering=1)
file.write("\n/*\n")
name = sys.argv[1].split(".")
li = [executable_name]
try:
    err = subprocess.run(li, stdout=file, stderr=subprocess.PIPE)
except Exception as e:
    print(err.stderr.decode('utf-8'))
    print("'\n\nEXECUTION FAILED\n\n")
    sys.exit()
file.write("*/\n")
file.close()
os.remove(executable_name)
