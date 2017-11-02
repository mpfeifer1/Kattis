n = int(input())
bac = 1;
rem = input().split()

for i in rem:
    bac *= 2;
    bac -= int(i);

    printed = False
    if bac < 0:
        print("error")
        printed = True
        break;

if not printed:
    print(bac % 1000000007)
