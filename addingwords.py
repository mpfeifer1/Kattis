import fileinput

words = {}
other = {}
for line in fileinput.input():
    line = line.split()

    # Clear out all of the word definitions
    if line[0] == "clear":
        words = {}
        other = {}

    # Set insert the word into both dictionaries
    if line[0] == "def":
        words[line[1]] = int(line[2])
        other[int(line[2])] = line[1]

    # Calculate the value of a string
    if line[0] == "calc":
        # Check that the first word is in the dictionary
        if line[1] not in words:
            for i in line[1:]:
                print(i, end=' ')
            print('unknown')
            continue

        # Get the first word out
        total = int(words[line[1]])
        output = line[1:]
        line = line[2:]

        # Check if any numbers in the LHS are unknown
        unknown = False
        for i in range(1, len(line), 2):
            if line[i] not in words:
                unknown = True

        # If any are, print that they are unknown
        if unknown:
            for i in output:
                print(i, end=' ')
            print('unknown')
            continue

        # Otherwise calculate the total
        for i in range(0, len(line), 2):
            if line[i] == '+':
                total += int(words[line[i+1]])
            if line[i] == '-':
                total -= int(words[line[i+1]])

        # Then, print it out
        for i in output:
            print(i, end=' ')
        else:
            if total in other:
                print(other[total])
            else:
                print('unknown')

