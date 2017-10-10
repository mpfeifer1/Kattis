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
        # Get new var names
        word = line[1]
        value = int(line[2])

        # Remove any existing old definitions
        if word in words:
            oldvalue = words[word]
            other.pop(oldvalue, None)


        # Add new definitions
        words[word] = value
        other[value] = word

    # Calculate the value of a string
    if line[0] == "calc":
        # Split into words and operators
        line = line[1:]
        var = line[::2]
        ops = line[1::2]

        # Keep track of whether answer is unknown
        unknown = False

        # Check all vars exist
        for variable in var:
            if variable not in words:
                unknown = True

        # Calculate total if they do
        if not unknown:
            # Calculate total
            total = words[var[0]]
            for i in range(len(ops)-1):
                if ops[i] == '+':
                    total += words[var[i+1]]
                if ops[i] == '-':
                    total -= words[var[i+1]]

            # Check answer exists
            if total not in other:
                unknown = True

        # Print answer
        for i in line:
            print(i, end=' ')
        if unknown:
            print('unknown')
        else:
            print(other[total])
