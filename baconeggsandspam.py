import sys

def main():
    while True:
        n = int(raw_input())
        if n == 0:
            break;

        foods = {}
        sortable = []


        for i in range(0, n):
            vars = sys.stdin.readline().split()
            for food in vars[1:]:
                if food not in foods:
                    foods[food] = [vars[0]]
                    sortable.append(food)
                else:
                    foods[food].append(vars[0])

        sortable.sort()

        for food in sortable:
            print food + ' ',
            foods[food].sort()
            print ' '.join(foods[food])

        print ''

if __name__ == "__main__":
    main()
