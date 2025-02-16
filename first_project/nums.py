def main():
    num = get_num("gimme a number")
    for i in range(1,11,1):
        print(f"{i} x {num} = {num * i}")
def get_num(descript):
    while True:
        try:
            n = int(input(f"{descript} "))
            return n
        except ValueError:
            print("bad boy")
main()