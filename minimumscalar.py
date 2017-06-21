def main():
    n = int(raw_input())

    for i in range(n):
        print "Case #" + str(i+1) + ":",
        m = int(raw_input())

        a = raw_input()
        b = raw_input()

        a = a.split()
        b = b.split()

        a = [int(k) for k in a]
        b = [int(k) for k in b]

        a.sort()
        b.sort(reverse=True)

        total = 0

        for j in range(m):
            total += a[j] * b[j]

        print total

if __name__ == "__main__":
    main()
