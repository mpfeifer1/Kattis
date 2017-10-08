import fileinput

def main():
    words = {}
    for line in fileinput.input():
        if line == '0\n':
            break
        if '=' in line:
            word, eq, val = line.split()
            words[word] = int(val)
        else:
            line = line.split()
            line = line[0::2]

            extrawords = []

            total = 0
            for i in line:
                try:
                    total += int(i)
                except:
                    if i in words:
                        total += words[i]
                    else:
                        extrawords.append(i)

            if total != 0:
                print(total, end=' ')
                for i in extrawords:
                    print('+', i, end=' ')
            else:
                print(extrawords[0], end=' ')
                for i in extrawords[1:]:
                    print('+', i, end=' ')
            print()

if __name__ == "__main__":
    main()
