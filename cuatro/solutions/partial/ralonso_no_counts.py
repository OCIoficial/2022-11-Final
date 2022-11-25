def impossible():
    print("imposible")
    exit(0)


def possible():
    print("posible")
    exit(0)


def get_fours(grid, glyph):
    """Returns:
    - 0 if there is no connect four
    - 1 if there is one or more connect fours and they could have all been made in the last turn
    - 2 if at least one must have been present before the last turn
    """

    # for row in grid:
    #     print(row)

    n = len(grid)
    row = None
    col = None
    for i in range(n):
        r_count = 0
        c_count = 0
        for j in range(n):
            if grid[i][j] == glyph:
                r_count += 1
                if r_count == 4:
                    if row is not None:
                        return 2
                    row = i
                if r_count > 7:
                    return 2
            else:
                r_count = 0
            if grid[j][i] == glyph:
                c_count += 1
                if c_count == 4:
                    if col is not None:
                        return 2
                    col = i
                if c_count > 7:
                    return 2
            else:
                c_count = 0
    # print("row", row, "col", col)
    if row is None and col is None:
        return 0
    if row is not None and col is not None:
        grid_copy = [row[:] for row in grid]
        grid_copy[row][col] = '.'
        if get_fours(grid_copy, glyph) > 0:
            return 2
    return 1


n = int(input())

grid = [[c for c in input()] for i in range(n)]

p1 = sum(row.count('O') for row in grid)
p2 = sum(row.count('X') for row in grid)

p1_fours = get_fours(grid, 'O')
p2_fours = get_fours(grid, 'X')

if p1_fours + p2_fours > 1:
    impossible()
if p1_fours == 0 and p2_fours == 0 and p1 + p2 < n * n:
    impossible()
else:
    possible()
