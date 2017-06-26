def main():
    x, y = raw_input().split()
    x = int(x)
    y = int(y)

    inputs = raw_input().split()
    inputs = [int(j) for j in inputs]

    foods = [0]
    for i in range(len(inputs)):
        foods.append(foods[i] + inputs[i])

    total = 0
    for i in range(1, len(foods)):
        for j in range(i, len(foods)):
            if foods[j] - foods[i-1] <= y and j - i + 1 > total:
                total = j - i + 1

    print total

if __name__ == "__main__":
    main()
