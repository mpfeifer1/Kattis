import fileinput

def main():
    words = {}
    wordcount = {}

    first = True
    for line in fileinput.input():
        # If first, continue
        if first:
            first = False
            continue

        # Split the line
        line = line.split()

        #Add person to the set
        if line[0] not in words:
            words[line[0]] = set()

        # Add all the person's words to their personal set
        for i in line[1:]:
            words[line[0]].add(i)
            wordcount[i] = wordcount.get(i, 0) + 1

    # Find all words
    allwords = set()
    for person in words:
        allwords.update(words[person])

    # Find all common words
    for person in words:
        allwords.intersection_update(words[person])

    if len(allwords) == 0:
        print("ALL CLEAR")

    else:
        tosort = [[wordcount[i], i] for i in allwords]
        tosort = sorted(tosort, key=lambda x:(-x[0], x[1]))
        for i in tosort:
            print(i[1])


if __name__ == "__main__":
    main()
