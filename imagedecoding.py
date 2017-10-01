import fileinput

first = True
images = []

for line in fileinput.input():
    # If not part of an image
    if line[0] not in ['#', '.']:
        # Add a new image
        images.append([])

    # If part of an image
    to_print = line[0]
    line = line[2:]

    # Add to image
    images[-1].append("")
    for i in line.split():
        i = int(i)
        for j in range(i):
            images[-1][-1] = images[-1][-1] + to_print
        if to_print == '#':
            to_print = '.'
        else:
            to_print = '#'


first = True
for i in images[:-1]:
    # Print lines between images
    if first:
        first = False
    else:
        print()

    # Strip newlines
    i = i[1:]

    # Print image
    for j in i:
        print(j)

    # Check if image is valid
    works = True
    for j in range(0, len(i)-1):
        if len(i[j]) != len(i[j+1]):
            works = False

    if not works:
        print("Error decoding image")
