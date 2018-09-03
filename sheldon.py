n, m = raw_input().split()
n = int(n)
m = int(m)

nums = set()

for a in range(1,64):
    for b in range(0,64):
        for c in range(1,64):
            s = '1' * a + '0' * b
            s1 = s * c
            s2 = s * c + '1' * a
            val1 = int(s1, 2)
            val2 = int(s2, 2)
            if(val1 >= 2**65):
                break
            nums.add(val1)
            if(val2 >= 2**65):
                break
            nums.add(val2)

nums = sorted(list(nums))

count = 0
for i in nums:
    if i >= n and i <= m:
        count += 1

print(count)
