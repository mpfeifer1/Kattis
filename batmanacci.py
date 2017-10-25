data = input()
data = data.split()
n = int(data[0])
k = int(data[1])

fib = [0,1,1]
for i in range(n+1):
    fib.append(fib[-1] + fib[-2])

while n > 2:
    if k > fib[n-2]:
        k -= fib[n-2]
        n -= 1
    else:
        n -= 2

if n == 1:
    print("N")

if n == 2:
    print("A")
