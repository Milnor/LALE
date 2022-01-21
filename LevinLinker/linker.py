#!/usr/bin/env python3

""" Linker Skeleton: Project 3.1 """

import sys

class ObjectFile:
    def __init__(self, nseg, nsym, nrel):
        self.n_segs = nseg
        self.n_syms = nsym
        self.n_rels = nrel

    def debug_me(self):
        print("OBJ = {} {} {}".format(self.n_segs, self.n_syms, self.n_rels))

def link_like_levin(data):
    """ Parse an object file """
    if data[0].strip() != 'LINK':
        print("[-] Bad object format: magic", file=sys.stderr)
        sys.exit(1)
    counts = data[1].split(" ")
    obj_file = ObjectFile(counts[0], counts[1], counts[2])
    obj_file.debug_me()

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
