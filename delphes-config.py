#!/usr/bin/env python
import os.path
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--cflags', action='store_true', help='Help text')
parser.add_argument('--incdir', action='store_true', help='Help text')
parser.add_argument('--libs', action='store_true', help='Help text')
parser.add_argument('--ldflags', action='store_true', help='Help text')
args = parser.parse_args()

prefix = os.path.realpath(os.path.dirname(__file__))

if args.cflags:
    print('-std=c++17 -I{} -I{}/external'.format(prefix, prefix))

if args.incdir:
    print('{} {}/external'.format(prefix, prefix))

if args.libs:
    print('-L{} -lDelphes -Wl,-rpath,{} -pthread -lm -ldl -rdynamic'.format(prefix, prefix))


if args.ldflags:
    print()