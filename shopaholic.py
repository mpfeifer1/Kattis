def main():
    n = int(raw_input())
    arr = raw_input().split()
    arr = [int(x) for x in arr]

    arr.sort(reverse=True)

    total = 0

    for i in range(0, len(arr)):
        if i % 3 == 2:
            total += int(arr[i])

    print total

if __name__ == "__main__":
    main()
