import random
import sys


def find_streaks(grid, N, player):
    # yapf: disable
    pos_dirs = ([((i, 0), (0, 1), 'c') for i in range(N)] +
                [((0, j), (1, 0), 'r') for j in range(N)] +
                [((i, 0), (1, 1), 'd') for i in range(N)] +
                [((0, j), (1, 1), 'd') for j in range(N)])
    # yapf: enable

    streaks = {'c': [], 'r': [], 'd': []}
    for (pos, (diri, dirj), dir) in pos_dirs:
        streak = 0
        (i, j) = pos
        while (i < N) and (j < N):
            if grid[i][j] == player:
                streak += 1
            else:
                if streak >= 4:
                    streaks[dir].append(pos)
                streak = 0
            i += diri
            j += dirj
    return streaks


def check_streaks(grid, N):
    streaks = find_streaks(grid, N)
    flatten = [n for v in streaks.values() for n in v]
    if any(n > 7 for n in flatten):
        return False
    if len(streaks['c']) > 1 or len(streaks['r']) > 1 or len(streaks['d']) > 1:
        return False


def check_move_count(grid):
    os = len(p == 'O' for row in grid for p in row)
    xs = len(p == 'X' for row in grid for p in row)
    return 0 <= os - xs <= 1


N = int(sys.argv[2])

grid = [[random.choice(['.', 'X', 'O']) for _ in range(N)] for _ in range(N)]

print(N)
for row in grid:
    print(''.join(row))
