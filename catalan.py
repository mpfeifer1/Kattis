fact = [1]

for i in range(1,10001):
    fact.append(fact[i-1] * i)

cases = int(input())
for i in range(cases):
    n = int(input())
    print(fact[2*n] // (fact[n+1]*fact[n]))
