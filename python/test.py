
# if 90 <= score <= 100:
#     print("A")
# elif score >= 80:
#     print("B")
# elif score >= 70:
#     print("C")
# elif score >= 60:
#     print("D")
# else:
#     print("F")
# dict1 = {"name":"wang",
#          "age":19,
#          "tele":"123",
#          "score":[123,124,145]}
# for i in dict1:
#     print(i,dict1[i],sep=",",end="\n")
def main():
    x = get_int("What's x? ")
    print(f"x is {x}")

def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
        except ValueError:
            pass
        else:
            break
    return n
if __name__ == "__main__":    main()