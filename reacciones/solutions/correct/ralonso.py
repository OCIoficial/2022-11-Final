from collections import defaultdict

counts = defaultdict(lambda: 0, {})

n, k = (int(i) for i in input().split())

message = input()

results = []

for i in message:
    counts[i] += 1
    if counts[i] > k:
        print("imposible")
        exit(0)
    results.append(counts[i])

print(" ".join(str(result) for result in results))
