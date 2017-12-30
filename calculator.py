import fileinput

for line in fileinput.input():
    line = line[:-1]
    line = "x = " + line
    exec(line)
    print("{0:.2f}".format(x))
