#!/usr/bin/env python3

""" Linker Skeleton: Project 3.1 """

import sys

class Segment:
    """ Segment within an object file """
    def __init__(self, name, start_address, length, code):
        self.name = name
        self.start_address = start_address
        self.length = length
        self.code = code

    def debug_me(self):
        """ Display basic segment info """
        print("{} {} {} {}".format(self.name, self.start_address, 
            self.length, self.code))

class ObjectFile:
    """ Class to hold an object file for dynamic linking """
    def __init__(self, magic, nsegs, nsyms, nrels, segments):
        self.magic = magic
        self.nsegs = nsegs
        self.nsyms = nsyms
        self.nrels = nrels
        self.segments = segments

    def verify_me(self):
        """ Am I well-formed? """
        # TODO: check segment count, etc.
        return True

    def debug_me(self):
        """ Display members of object """
        print("{}".format(self.magic))
        print("{} {} {}".format(self.nsegs, self.nsyms, self.nrels))
        for segment in self.segments:
            segment.debug_me()

def parse_segments(data):
    """ Return list of segments and remaining unprocessed data """
    segments = []
    remainder = []
    for line in data:
        if line[0] == '.':
            components = line.split(" ")
            segment = Segment(components[0], components[1], components[2],
                    components[3])
            segments.append(segment)
        else:
            remainder.append(line)
    return segments, remainder

def link_like_levine(raw_data):
    """ Parse an object file """
    magic = ""
    nsegs = 0
    nsyms = 0
    nrels = 0
    try:
        # Strip comments
        data = []
        for line in raw_data:
            if line[0] != '#':
                data.append(line)
        # Read magic number
        magic = data[0].strip()
        if magic != 'LINK':
            raise ValueError("Bad magic: {}, expected \'LINK\'".format(magic))
        # Read segment, symbol, and relocation counts
        counts = data[1].split(" ")
        nsegs = int(counts[0])
        nsyms = int(counts[1])
        nrels = int(counts[2])
        # Parse the segment(s)
        segment_list, remaining_data = parse_segments(data[2:])
    except ValueError as bad_val:
        print("[-] {}".format(bad_val), file=sys.stderr)
        sys.exit(1)
    obj_file = ObjectFile(magic, nsegs, nsyms, nrels, segment_list)
    if obj_file.verify_me():
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
