import fileinput

def main():
    words = {}
    for line in fileinput.input():
        line = line.split()
        if line[0] == "define":
            words[line[2]] = int(line[1])
        if line[0] == "eval":
            try:
                to_print = True
                if line[2] == ">":
                    to_print = words[line[1]] > words[line[3]]
                if line[2] == "<":
                    to_print = words[line[1]] < words[line[3]]
                if line[2] == "=":
                    to_print = words[line[1]] == words[line[3]]

                if to_print:
                    print("true")
                else:
                    print("false")

            except:
                print("undefined")


if __name__ == "__main__":
    main()
