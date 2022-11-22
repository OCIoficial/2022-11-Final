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
tower = gen_tower(m-1)
print(len(tower)+1, m-1, *tower)

for i in range(n-1):
    tower = gen_tower(m)
    print(len(tower), *tower)
