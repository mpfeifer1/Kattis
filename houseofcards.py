def get_num_cards(height):
    return (3 * height**2 + height) // 2

def main():
    height = int(input())

    while get_num_cards(height) % 4 != 0:
        height += 1

    print(height)

if __name__ == "__main__":
    main()
