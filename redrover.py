s = input()

best = len(s)
for i in range(len(s)):
    for j in range(i+1, len(s)):
        temp = s[i:j]
        replaced = s.replace(temp, "M")
        best = min(best, len(replaced) + len(temp))

print((best))
