#!/usr/bin/python
from scripts.fabricate import *
from scripts.settings import *
from scripts.utils import listfiles
from sys import argv

# Acciones
def build():
  compile()
  link()

def compile():
  for source in sources:
    # '-L/usr/local/libopencv_core.so', '-L/usr/local/lib/libopencv_video.so', '-L/usr/local/lib/libopencv_highgui.so', '-L/usr/local/lib/libopencv_imgproc.so',
    run(compiler, '-std=c++11', '-c', source+'.cpp', '-o', source+'.o')

def link():
  objects = [s+'.o' for s in sources]
  run(compiler, '-o', executable, objects)

def clean():
  autoclean()

def test():
  build()
  import unittest
  unittest.main(module='scripts.tptests', exit=False, argv=argv[:1], verbosity=3)

main()
