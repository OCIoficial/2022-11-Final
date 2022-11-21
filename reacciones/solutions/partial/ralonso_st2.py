n, k = (int(i) for i in input().split())
message = input()

results = []

for i, glyph in enumerate(message):
    count = message[:i].count(glyph) + 1
    if count > k:
        print("imposible")
        exit(0)
    results.append(count)

print(" ".join(str(result) for result in results))
