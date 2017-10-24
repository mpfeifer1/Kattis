import fileinput, fractions

def calc(t1, t2, b1, b2):
    b = b1*b2
    return t1*b2, t2*b1, b, b



def main():
    first = True
    for line in fileinput.input():
        if first:
            first = False
            continue

        # Read input
        t1, b1, op, t2, b2 = line.split()
        t1 = int(t1)
        t2 = int(t2)
        b1 = int(b1)
        b2 = int(b2)

        # Make positive
        if b1 < 0:
            t1 *= -1
            b1 *= -1
        if b2 < 0:
            t2 *= -1
            b2 *= -1

        # Set up top and bottom
        t = None
        b = None

        # Add
        if op == '+':
            t1, t2, b1, b2 = calc(t1, t2, b1, b2)
            t = t1+t2
            b = b1

        # Subtract
        if op == '-':
            t1, t2, b1, b2 = calc(t1, t2, b1, b2)
            t = t1-t2
            b = b1

        # Multiply
        if op == '*':
            t1, t2, b1, b2 = calc(t1, t2, b1, b2)
            t = t1*t2
            b = b1*b2

        # Divide
        if op == '/':
            t = t1*b2
            b = t2*b1


        # Simplify
        div = fractions.gcd(t, b)
        while div != 1:
            t //= div
            b //= div
            div = fractions.gcd(t, b)

        # Make positive
        if b < 0:
            t *= -1
            b *= -1

        # Print
        print(t, '/', b)


if __name__ == "__main__":
    main()
