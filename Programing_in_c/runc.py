#!/usr/bin/env python3
import os
import sys

def compile(name,arg):
    print(f"compiles {name}")
    os.system(f"gcc {name} -lm -o temp.out")
def run(prev=""):
    os.system(f"{prev} ./temp.out")
    os.system("rm -rf ./temp.out")

def getPath(name):
        for (root,dirs,files) in os.walk('.', topdown=True):
            for file in files:
                if file == name:
                    path = (os.path.join(root,file))
                    return path

if len(sys.argv) > 0 and sys.argv[1] == "i":
    path = getPath(sys.argv[2])
    compile(path,"")
    run("cat input| ")
elif len(sys.argv) > 0:
    path = getPath(sys.argv[1])
    compile(path,"")
    run()
