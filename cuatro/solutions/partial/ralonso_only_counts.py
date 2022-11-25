def impossible():
    print("imposible")
    exit(0)


def possible():
    print("posible")
    exit(0)


n = int(input())

grid = [[c for c in input()] for i in range(n)]

p1 = sum(row.count('O') for row in grid)
p2 = sum(row.count('X') for row in grid)

if p1 - 1 == p2:
    possible()
elif p1 == p2:
    possible()
else:
    impossible()
