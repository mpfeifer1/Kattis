import fileinput

for line in fileinput.input():
    line = line[:-1]

    if '=' in line:
        print('skipped')

    if '+' not in line:
        continue

    line = line.split('+')
    print(int(line[0]) + int(line[1]))
