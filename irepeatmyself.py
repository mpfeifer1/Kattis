import fileinput

def main():
    first = True
    for line in fileinput.input():
        line = line[:-1]
        if first:
            first = False
            continue
        printed = False
        for i in range(1, len(line)):
            templine = line[0:i]
            templine = templine * len(line)
            templine = templine[:len(line)]
            if templine == line:
                printed = True
                print(i)
                break
        if not printed:
            print(len(line))

if __name__ == "__main__":
    main()
