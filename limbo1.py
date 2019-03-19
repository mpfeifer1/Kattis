n = int(input())

def get(n):
    return n * (n-1) / 2

for i in range(n):
    l,r = map(int,raw_input().split())

    ''' NAIVE
    ans = 1
    for i in range(l):
        ans += i+1
    for i in range(r):
        ans += i+l+2

    print(ans)
    '''

    ans = 1
    ans += l
    ans += 2*r
    ans += get(l+r)

    print(ans)
