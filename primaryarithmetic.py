import fileinput

def main():
    for line in fileinput.input():
        a, b = line.split()
        if a == '0' and b == '0':
            break
        a = a.zfill(10)
        b = b.zfill(10)

        a = a[::-1]
        b = b[::-1]

        carries = 0
        carry = 0
        for i in range(10):
            if int(a[i]) + int(b[i]) + carry > 9:
                carries += 1
                carry = 1
            else:
                carry = 0

        if carries == 0:
            print("No carry operation.")
        if carries == 1:
            print("1 carry operation.")
        if carries > 1:
            print(carries, "carry operations.")


if __name__ == "__main__":
    main()
