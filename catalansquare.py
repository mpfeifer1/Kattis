n = int(input())

catalan = {}
catalan[0] = 1

for i in range(0,n+1):
    catalan[i+1] = catalan[i] * (4*i + 2) // (i+2)

print(catalan[n+1])
