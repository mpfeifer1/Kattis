import sys

def main():
    for line in sys.stdin:
        name = ""
        numbers = []
        for item in line.split():
            try:
                float(item)
            except:
                name += item + " "
            else:
                numbers.append(float(item))

        total = 0

        for num in numbers:
            total += num

        avg = total / len(numbers),
        print '%.6f' % avg,
        print name

if __name__ == "__main__":
    main()
