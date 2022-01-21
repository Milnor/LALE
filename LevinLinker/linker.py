#!/usr/bin/env python3

""" Linker Skeleton: Project 3.1 """

import sys

def link_like_levin(data):
    """ Parse an object file """
    magic = obj.readlines()
def main():
    """ Read in an object file and spit it back out """
    if len(sys.argv) < 2:
        print("Usage: {} object_file".format(sys.argv[0]))
        sys.exit(0)
    try:
        with open(sys.argv[1], 'r') as obj:
            link_like_levin(obj.readlines())
    except FileNotFoundError:
        print("[-] Can't find {}".format(sys.argv[1]), file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
