import os, sys

sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))

import random
from solutions.correct.nlehmann import check


def gen(N):
    return [[random.choice(['.', 'X', 'O']) for _ in range(N)]
            for _ in range(N)]


if __name__ == "__main__":
    random.seed(sys.argv[1])
    N = int(sys.argv[2])

    grid = gen(N)
    if sys.argv[3] == 'impossible':
        while check(grid, N):
            grid = gen(N)
    elif sys.argv[3] == 'possible':
        while not check(grid, N):
            grid = gen(N)
    else:
        print("invalid argument")
        sys.exit(0)

    print(N)
    for row in grid:
        print(''.join(row))
