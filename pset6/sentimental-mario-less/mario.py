while True:
    try:
        height = int(input("Height: "))
        if (height >= 1) and (height <= 8):
            break
    except:
        print("", end="")

space = 1

for k in range(height):

    # prints space

    for space in range(height-k-1):
        print(" ", end="")

    # prints hash
    for i in range(k+1):
        print("#", end="")

    print()