import fileinput

def myequal(str1, str2):
    lentocheck = min(len(str1), len(str2))
    thisworks = True
    for i in range(lentocheck):
        if str1[i] != str2[i]:
            thisworks = False
    return thisworks


def main():
    word = None
    rhymeschemes = []
    phrases = []
    validrhymes = []

    ints = 0
    for line in fileinput.input():
        try:
            int(line)
            ints += 1
        except:
            if ints == 0:
                word = line[:-1]
            if ints == 1:
                rhymeschemes.append(line.split())
            if ints == 2:
                phrases.append(line[:-1])

    word = word[::-1]

    for scheme in rhymeschemes:
        works = False
        for rhyme in scheme:
            rhyme = rhyme[::-1]
            works |= myequal(rhyme, word)

        if works:
            for rhyme in scheme:
                validrhymes.append(rhyme[::-1])

    for phrase in phrases:
        works = False
        for rhyme in validrhymes:
            if myequal(rhyme, phrase[::-1]):
                works = True
        if works:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
