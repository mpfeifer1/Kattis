import sys

def main():
    n = int(raw_input())

    while n > 0:
        n -= 1
        words = sys.stdin.readline().split()

        while True:
            line = sys.stdin.readline()
            if line == 'what does the fox say?\n':
                break
            word = line.split()[-1]
            words = [i for i in words if i != word]

        for word in words:
            print word,

        print ""

if __name__ == "__main__":
    main()
