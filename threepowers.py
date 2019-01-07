def solve(n):
    v = []

    curr = 1;
    while n > 0:
        if n % 2 == 1:
            v.append(curr)
        curr *= 3
        n //= 2

    print("{ ", end="")
    for i in range(len(v)):
        print(v[i], end="")
        if i != len(v)-1:
            print(",", end="")
        print(" ", end="")
    print("}")

while True:
    n = int(input())
    if n == 0:
        break
    solve(n-1)
