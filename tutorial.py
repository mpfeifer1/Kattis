import math

def main():
    limit, n, operation = input().split()

    limit = int(limit)
    n = int(n)
    operation = int(operation)

    # ans stores if it's too long

    if operation == 1:
        if n > 15:
            ans = True
        else:
            ans = limit < math.factorial(n)

    if operation == 2:
        ans = limit < 2**n

    if operation == 3:
        ans = limit < n**4

    if operation == 4:
        ans = limit < n**3

    if operation == 5:
        ans = limit < n**2

    if operation == 6:
        ans = limit < n * math.log(n, 2)

    if operation == 7:
        ans = limit < n

    if ans:
        print("TLE")
    else:
        print("AC")


if __name__ == "__main__":
    main()
