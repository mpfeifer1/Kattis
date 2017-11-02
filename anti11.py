memo = [0, 2, 3, 5]

cases = int(input())

for i in range(3, 10005):
    memo.append(memo[i-1] + memo[i])

for i in range(cases):
    n = int(input())

    print(memo[n] % 1000000007)
