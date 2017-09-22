import fileinput

def ishex(string, loc):
    if len(string) <= loc:
        return False
    if len(string) < 2:
        return False
    return string[loc] == '0' and string[loc+1] in ['x', 'X']

def ishexdigit(letter):
    if letter.lower() in ['a', 'b', 'c', 'd', 'e', 'f']:
        return True
    if letter.lower() in ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']:
        return True
    return False

def main():
    for line in fileinput.input():
        hexcodes = [[]]

        # Split on 0x or 0X
        for i in range(0, len(line)-1):
            if ishex(line, i):
                hexcodes.append([])
            hexcodes[-1].append(line[i])

        # Convert to list of strings
        hexcodes = [''.join(i) for i in hexcodes]

        # Remove all without 0x
        hexcodes = [i for i in hexcodes if ishex(i, 0)]

        # Remove ends of strings if not valid
        goodcodes = []
        for i in hexcodes:
            goodcodes.append([])
            goodcodes[-1].append(i[0])
            goodcodes[-1].append(i[1])
            for letter in i[2:]:
                if(ishexdigit(letter)):
                    goodcodes[-1].append(letter)
                else:
                    break

        # Convert to list of strings
        hexcodes = [''.join(i) for i in goodcodes]

        # Remove empty strings
        hexcodes = [i for i in hexcodes if len(i) > 2]

        for i in hexcodes:
            print(i, int(i, 16))

if __name__ == "__main__":
    main()
