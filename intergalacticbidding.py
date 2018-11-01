import fileinput

ct = 0
bidders = []

for line in fileinput.input():
    if ct == 0:
        n, m = line.split()
        n = int(n)
        m = int(m)
    else:
        line = line.split()
        bidders.append([line[0], int(line[1])])
    ct += 1

bidders = sorted(bidders, key = lambda x : (-x[1]))

ans = []
for i in bidders:
    if m - i[1] >= 0:
        m -= i[1]
        ans.append(i[0])

if m == 0:
    print(len(ans))
    for i in ans:
        print(i)
else:
    print(0)

