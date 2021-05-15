import os
import sys
import signal
import argparse
import subprocess
from colorama import Fore

class MyExceptions:

    def __init__():
        super.__init__()
    
    @staticmethod
    def segMentationFault(err):
        print(Fore.MAGENTA + "Segmentation Fault occured")
        print(Fore.MAGENTA + err)


if sys.platform == "linux":
    executable_name = "a.out"
else:
    executable_name = "a.exe"

n = len(sys.argv)
li = ["c++", "-o", "a.out", "-g", "-O3"]
for i in range(1, len(sys.argv)):
    li.append(sys.argv[i])

err = subprocess.run(li, stderr=subprocess.PIPE)
if len(err.stderr.decode('utf-8')) != 0:
    print(err.stderr.decode('utf-8'))
    print("'\n\nBUILD FAILED\n\n")
    sys.exit()
inp = open("inp", 'r')
out = open('out', 'w')
res = open('res', 'r')
# # print(subprocess.run(["./a.out", "<", "inp"]))

try:
    err = subprocess.run(['./a.out'], stdin=inp, stdout=out, stderr=subprocess.PIPE)
    if err.returncode != 0:
        if err.returncode == -11:
            signal.signal(signal.SIGSEGV, MyExceptions.segMentationFault(err))

except Exception as e:
    print(Fore.RED + err.stderr.decode('utf-8'))
    print(Fore.RED + "'\nEXECUTION FAILED\n")
    sys.exit()
print(Fore.GREEN + "Execution completed...!!!")
print(Fore.YELLOW + "Find the output in out file in current directory")
inp.close()
out.close()

with open('res', 'r') as file1:
    with open('out', 'r') as file2:
        same = set(file1).difference(file2)

same.discard('\n')
with open('diff.txt', 'w') as file_out:
    for line in same:
        file_out.write(line)