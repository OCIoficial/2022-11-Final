def impossible():
    print("imposible")
    exit(0)


def possible():
    print("posible")
    exit(0)


def get_fours(grid, glyph):
    n = len(grid)
    rows = 0
    cols = 0
    for i in range(n):
        r_count = 0
        c_count = 0
        for j in range(n):
            if grid[i][j] == glyph:
                r_count += 1
                if r_count == 4:
                    rows += 1
                    r_count = 0
            else:
                r_count = 0
            if grid[j][i] == glyph:
                c_count += 1
                if c_count == 4:
                    cols += 1
                    c_count = 0
            else:
                c_count = 0
    return max(rows, cols)


n = int(input())

grid = [[c for c in input()] for i in range(n)]

p1 = sum(row.count('O') for row in grid)
p2 = sum(row.count('X') for row in grid)

p1_fours = get_fours(grid, 'O')
p2_fours = get_fours(grid, 'X')
# print("p1_fours", p1_fours, "p2_fours", p2_fours)

if p1 - 1 == p2:
    if p2_fours > 0:
        impossible()
    if p1_fours > 1:
        impossible()
    if p1_fours == 0 and p1 + p2 < n * n:
        impossible()
    possible()
elif p1 == p2:
    if p1_fours > 0:
        impossible()
    if p2_fours > 1:
        impossible()
    if p2_fours == 0 and p1 + p2 < n * n:
        impossible()
    possible()
else:
    impossible()
