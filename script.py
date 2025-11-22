def loop_output(n):
    count = 0
    _round = False

    for i in range(1, n + 1):
        count += 1

        if i % 2 == 0:
            print("Boo")
        else:
            print("Peek")

        if count == 30:
            if not _round:
                print("Made it to the first 30!")
                _round = True  # now _round is True
            else:
                print("Another fold of 30!")
            count = 0  # reset the count after 30

if __name__ == "__main__":
    num = int(input("Enter the number of loops: "))
    loop_output(num)
