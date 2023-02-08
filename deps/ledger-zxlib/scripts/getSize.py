#!/usr/bin/env python3

from ledgerblue.hexParser import IntelHexParser
from math import ceil
import sys

block_size = 2 if sys.argv[1] == "s" else 4
parser = IntelHexParser("app/bin/app.hex")
bytes = parser.maxAddr() - parser.minAddr()
size = ceil(bytes / (block_size * 1024)) * block_size
print(size)
