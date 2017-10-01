l, r = raw_input().split()
l = int(l)
r = int(r)

def f(x):
    i = 0
    while x != 1:
        if x % 2 == 0:
            x /= 2
        else:
            x += 1
        i += 1
    return i

def solve(l, r):
    if l == r:
        return f(l)

    if l == 1:
        return solve(l+1, r)

    if l % 2 == 0:
        return solve(l+1, r) + f(l)

    if r % 2 == 1:
        return solve(l, r-1) + f(r)

    return 2*solve((l+1)/2, r/2) + 3*(r - l + 1)/2

print int(solve(l, r) % (10**9 + 7))
