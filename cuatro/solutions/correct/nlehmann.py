from dataclasses import dataclass
from typing import Tuple, Dict, List


@dataclass
class Streak:
    len: int
    pos: Tuple[int, int]


def check(grid, N) -> bool:
    os = len([p for row in grid for p in row if p == 'O'])
    xs = len([p for row in grid for p in row if p == 'X'])
    streaksX = find_streaks(grid, N, 'X')
    streaksO = find_streaks(grid, N, 'O')

    # Only one of them must have streaks
    if has_streaks(streaksO):
        if has_streaks(streaksX) or os != xs + 1:
            return False
        return check_streaks(streaksO)
    if has_streaks(streaksX):
        if has_streaks(streaksO) or os != xs:
            return False
        return check_streaks(streaksX)

    # If the are no streaks there's no winner, so we must have a tie
    return all(p != '.' for row in grid for p in row)


def has_streaks(streaks: Dict[str, List[Streak]]) -> bool:
    return len(streaks['c']) > 0 or len(streaks['r']) > 0


def check_move_count(grid):
    os = len([p for row in grid for p in row if p == 'O'])
    xs = len([p for row in grid for p in row if p == 'X'])
    # `O` plays first so we could have one more `O` than `X`s
    return 0 <= os - xs <= 1


def find_streaks(grid, N, player) -> Dict[str, List[Streak]]:
    # yapf: disable
    pos_dirs = ([((i, 0), (0, 1), 'c') for i in range(N)] +
                [((0, j), (1, 0), 'r') for j in range(N)])
    # yapf: enable

    streaks: Dict[str, List[Streak]] = {'c': [], 'r': []}
    for ((i, j), (diri, dirj), dir) in pos_dirs:
        streak = 0
        pos = None
        while (i < N) and (j < N):
            if grid[i][j] == player:
                if pos is None:
                    pos = (i, j)
                streak += 1
            else:
                if streak >= 4 and pos is not None:
                    streaks[dir].append(Streak(len=streak, pos=pos))
                pos = None
                streak = 0
            i += diri
            j += dirj
        if streak >= 4 and pos is not None:
            streaks[dir].append(Streak(len=streak, pos=pos))
    return streaks


def check_streaks(streaks: Dict[str, List[Streak]]) -> bool:
    # If there's only one streak then we are fine if it is less than or equal to 7
    if len(streaks['c']) == 1 and len(streaks['r']) == 0:
        return streaks['c'][0].len <= 7
    if len(streaks['r']) == 1 and len(streaks['c']) == 0:
        return streaks['r'][0].len <= 7

    # If we complete one column and one row in the last move then they must intersect
    if len(streaks['c']) == 1 and len(streaks['r']) == 1:
        streak1 = streaks['c'][0]
        streak2 = streaks['r'][0]
        if streak1.len > 7 or streak2.len > 7:
            return False
        (i1, j1) = streak1.pos
        (i2, j2) = streak2.pos
        for _ in range(streak1.len):
            if j1 == j2 and i2 <= i1 <= i2 + streak2.len:
                return streak1.len - j1 <= 4
            j1 += 1

    # Otherwise is invalid
    return False


if __name__ == "__main__":
    N = int(input())
    grid = [list(input()) for _ in range(N)]

    if check(grid, N):
        print("posible")
    else:
        print("imposible")
