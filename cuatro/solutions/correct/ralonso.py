def impossible():
    print("imposible")
    exit(0)


def possible():
    print("posible")
    exit(0)


def get_fours(grid, glyph):
    # TODO revisar si hay 4 en fila y columna
    # si hay en ambos, asegurarse que al quitar la intersección ya no haya
    # si no hay en ambos, asegurarse que fue una vez, y a lo más 7 en línea


n = int(input())

grid = [[c for c in input()] for i in range(n)]

p1 = 0
p2 = 0

p1 = sum(row.count('O') for row in grid)
p2 = sum(row.count('X') for row in grid)

p1_fours = get_fours(grid, 'O')
p2_fours = get_fours(grid, 'X')

if p1 - 1 == p2:
    if p2_fours > 0:
        impossible()
    if p1_fours > 1:
        impossible()
    if p1_fours == 0 && p1 + p2 < n * n:
        impossible()
    possible()
elif p1 == p2:
    if p1_fours > 0:
        impossible()
    if p2_fours > 1:
        impossible()
    if p2_fours == 0 && p1 + p2 < n * n:
        impossible()
    possible()
else:
    impossible()
