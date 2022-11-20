"""
Generates a case for given k where m - 1 letters of the alphabet are repeated k
times, and another letter which is repeated k + 1 times and appears as the
first and the last letter in the message (to ensure the entire message is being
consumed).
"""
import random
import sys

if __name__ == '__main__':
    random.seed(sys.argv[1])

    k = int(sys.argv[2])
    m = int(sys.argv[3])
    n = m * k + 1

    glyphs = random.sample(list(chr(code) for code in range(97, 123)), m) * k
    random.shuffle(glyphs)
    glyphs.append(glyphs[0])

    print(n, k)
    print("".join(glyphs))
