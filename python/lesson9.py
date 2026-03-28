import argparse
# contact = set()
# contact.add(1)
# contact.add(2)
# print(contact)

# num = 4

# def change_num(n):
#     global num
#     num += n
#     return num

NUM = 3

def ADD(n: int) -> int:
    """
    Add 1-n natural numbers
    :param n: add 1 to n
    :type n: int
    :raise TypeError: If n is not an int
    :rtype: int
    """

    if not isinstance(n,int):
        raise TypeError("n is not an int")
    if n <= 0:
        return 0
    return n + ADD(n-1)

def Fac(n: int) -> int:
    if not isinstance(n,int):
        raise TypeError("n is not an int")
    if n <= 0:
        return 1
    return n * Fac(n-1)

def get_args():
    """
        Get the arguments from the command line
        :return: Parsed arguments
    """
    parser = argparse.ArgumentParser(description="Calculate Add or Factorial")
    parser.add_argument("-a",default=0,help="add numbers from 1 to n",type=int)
    parser.add_argument("-f",default=0,help="Calculate n factorial.",type=int)
    return parser.parse_args()

def mutiple(*number: int|float) -> int|float:
    """
       Receive several numbers and then return their mutiplication.
    """
    ret = 1
    for i in number:
        ret *= i
    return ret

def read_info(**info) -> dict:
      # 遍历字典时提取的是key！！！
    return info

def upper_string(*arg):
    result = map(str.upper,arg)
    return list(result)

def is_prime(x: int) -> bool:
    if x <= 1: return False
    if x == 2: 
        return True
    if x % 2 == 0: 
        return False
    for i in range(3,x//2,2):
        if x % i == 0:
            return False
    return True



def main():
    # args = get_args()
    # if args.a != 0 : print(ADD(args.a))
    # if args.f != 0 : print(Fac(args.f))
    # print(mutiple(2,1,4,2))

    # print(*upper_string("hello","world","!"),sep=' ')
    test = [2,4,15,36,36,0,6,74,8,5,89,1]
    print(*filter(is_prime,test))
if __name__ == "__main__":
    main()
