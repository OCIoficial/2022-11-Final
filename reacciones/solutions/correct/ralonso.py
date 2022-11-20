from collections import defaultdict

counts = defaultdict(lambda: 0, {})

n, k = (int(i) for i in input().split())

message = input()

results = []

for glyph in message:
    counts[glyph] += 1
    if counts[glyph] > k:
        print("imposible")
        exit(0)
    results.append(counts[glyph])

print(" ".join(str(result) for result in results))
