def mario(height):
    for i in range(height):
        spaces = " " *(height-i)
        bricks= "#" * i
        print(f"{spaces}{bricks}  {bricks}")
def get_height():
    integer= int(input("Height"))
    try:
        return integer
    except:
        print("not an integer")

def main():
    size = get_height()
    mario(size)
main()
