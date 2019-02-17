n, m = map(int, input().split())

ans = 0
currNode = 2
currWeight = 1

while currNode <= n:
    ans += currWeight
    currWeight = currWeight+1
    m = m-1
    edgesWasted = max(0, currNode-2)
    edgesNeeded = n-currNode
    edgesWasted = min(edgesWasted, m-edgesNeeded)
    m -= edgesWasted
    currWeight += edgesWasted
    currNode = currNode+1

print(ans)


