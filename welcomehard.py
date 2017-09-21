import fileinput

def main():
    n = int(input())

    count = 1
    for line in fileinput.input():
        # Set up our strings
        v = []
        v.append("w")
        v.append("we")
        v.append("wel")
        v.append("welc")
        v.append("welco")
        v.append("welcom")
        v.append("welcome")
        v.append("welcome ")
        v.append("welcome t")
        v.append("welcome to")
        v.append("welcome to ")
        v.append("welcome to c")
        v.append("welcome to co")
        v.append("welcome to cod")
        v.append("welcome to code")
        v.append("welcome to code ")
        v.append("welcome to code j")
        v.append("welcome to code ja")
        v.append("welcome to code jam")

        # Solve the problem
        ans = {}
        for i in v:
            ans[i] = 0

        for i in line:
            for j in range(0, len(v)):
                if i == v[j][-1]:
                    if j == 0:
                        ans[v[j]] += 1;
                    else:
                        ans[v[j]] += ans[v[j-1]];

        total = ans[v[-1]];

        # Make exactly 4 characters
        t = str(total)
        while len(t) > 4:
            t = t[1:]

        while len(t) < 4:
            t = '0' + t

        #print("Case #", count, ": ", t, " ", total, sep='')
        print("Case #", count, ": ", t, sep='')
        count += 1


if __name__ == "__main__":
    main()
