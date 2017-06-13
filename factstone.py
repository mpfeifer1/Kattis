import sys

def getBitsFromYear(year):
    year = long(year)
    year -= 1940
    year /= 10
    return 2**year

def getMaxFromBits(bits):
    return (2**(bits))-1

def getHighestFactorial(num):
    ret = 1
    count = 1

    while(ret < num):
        count += 1
        ret *= count

    return count - 1

def main():
    for line in sys.stdin:
        if line == '0\n':
            break

        bits = getBitsFromYear(line)
        max = getMaxFromBits(bits)
        fact = getHighestFactorial(max)
        print fact

if __name__ == "__main__":
    main()

