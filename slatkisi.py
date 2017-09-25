import fileinput

def main():
    for line in fileinput.input():
        cost, zeros = line.split()

    cost = int(cost)
    zeros = int(zeros)

    zeros = 10 ** zeros

    cost /= zeros
    cost = round(cost)
    cost *= zeros

    print(cost)

if __name__ == "__main__":
    main()
