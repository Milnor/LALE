#!/usr/bin/env python3

""" Linker Skeleton: Project 3.1 """

import sys

class ObjectFile:
    """ Class to hold an object file for dynamic linking """
    def __init__(self, magic, nsegs, nsyms, nrels):
        self.magic = magic
        self.nsegs = nsegs
        self.nsyms = nsyms
        self.nrels = nrels

    def debug_me(self):
        """ Display basic object info """
        print("OBJ = {} {} {}".format(self.nsegs, self.nsyms, self.nrels))

def link_like_levine(data):
    """ Parse an object file """
    magic = ""
    nsegs = 0
    nsyms = 0
    nrels = 0
    try:
        magic = data[0].strip()
        if magic != 'LINK':
            raise ValueError("Bad magic: {}, expected \'LINK\'".format(magic))
        counts = data[1].split(" ")
        nsegs = int(counts[0])
        nsyms = int(counts[1])
        nrels = int(counts[2])
    except ValueError as bad_val:
        print(bad_val, file=sys.stderr)
        sys.exit(1)
    obj_file = ObjectFile(magic, nsegs, nsyms, nrels)
    obj_file.debug_me()

def main():
    """ Read in an object file and spit it back out """
    if len(sys.argv) < 2:
        print("Usage: {} object_file".format(sys.argv[0]))
        sys.exit(0)
    try:
        with open(sys.argv[1], 'r') as obj:
            link_like_levine(obj.readlines())
    except FileNotFoundError:
        print("[-] Can't find {}".format(sys.argv[1]), file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
