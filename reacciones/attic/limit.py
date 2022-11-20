"""
Generates a case for given k where m letters of the alphabet are repeated k
times.
"""
import random
import sys

if __name__ == '__main__':
    random.seed(sys.argv[1])

    k = int(sys.argv[2])
    m = int(sys.argv[3])
    n = m * k

    glyphs = random.sample(list(chr(code) for code in range(97, 123)), m) * k
    random.shuffle(glyphs)

    print(n, k)
    print("".join(glyphs))
