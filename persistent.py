import fileinput

for line in fileinput.input():
    if line == "-1\n":
        continue

    line = int(line)
    if line < 10:
        print(line + 10)
    else:
        factors = []
        works = True
        while line >= 10:
            divided = False
            for i in range(9, 2, -1):
                if line % i == 0:
                    divided = True
                    line //= i
                    factors.append(i)
                    break

            if not divided:
                works = False
                break

        factors.append(line)

        if works:
            factors.sort()
            for i in factors:
                print(i, end='')
            print()
        else:
            print("There is no such number.")
