from string import ascii_lowercase

n, k = [int(x) for x in input().split()]
msg = input()

counts = {c: 0 for c in ascii_lowercase}
res = []
for c in msg:
    counts[c] += 1
    res.append(str(counts[c]))
if any(v > k for v in counts.values()):
    print("imposible")
else:
    print(' '.join(res))
