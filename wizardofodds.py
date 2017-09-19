def main():
    number, guess = input().split()
    number = int(number)
    guess = int(guess)

    if 2 ** guess >= number:
        print("Your wish is granted!")
    else:
        print("You will become a flying monkey!")


if __name__ == "__main__":
    main()
