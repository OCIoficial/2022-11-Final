_ = input()
message = input()

for i, glyph in enumerate(message):
    if glyph in message[:i]:
        print("imposible")
        exit(0)

print(" ".join(["1"] * len(message)))
