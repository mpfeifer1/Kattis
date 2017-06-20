def main():
    n = int(raw_input())
    temp = (n/2)+1
    ans = temp**2
    if n % 2 == 1:
        ans += temp
    print ans

if __name__ == '__main__':
    main()
