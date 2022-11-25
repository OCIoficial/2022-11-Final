n, k = [int(x) for x in input().split(' ')]

s = input()

v = [1]*26

ans = []
for c in s:
    i = ord(c) - ord('a')
    if v[i] > k:
        print("imposible")
        exit(0)
    ans.append(str(v[i]))
    v[i] += 1

print(' '.join(ans))

