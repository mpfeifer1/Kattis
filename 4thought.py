import sys

def main():
    ans = {}

    ops = [' / ', ' * ', ' - ', ' + ']

    for i in ops:
        for j in ops:
            for k in ops:
                temp = '4' + i + '4' + j + '4' + k + '4'
                val = eval(temp.replace('/','//'))
                ans[val] = temp

    n = input()
    for line in sys.stdin:
        line = line[:-1]
        if int(line) in ans:
            print(str(ans[int(line)]) + ' = ' + line)
        else:
            print('no solution')

if __name__ == "__main__":
    main()
