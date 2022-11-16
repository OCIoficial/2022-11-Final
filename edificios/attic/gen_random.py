#!/usr/bin/env python3
"""
Generates testcases in which there is always
at least 1 safe floor per tower
such that there is always a valid path
"""
import random
import sys

random.seed(sys.argv[1])

def gen_tower(m):
    return random.sample(range(0, m), random.randint(1, m))

n = int(sys.argv[2])
m = int(sys.argv[3])

print(n, m)
for i in range(n):
    tower = gen_tower(m)
    print(len(tower), *tower)
