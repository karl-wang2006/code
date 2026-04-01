list1=[]
# while True:
#     digit=input("Please enter a number (q to quit): ")
#     if digit.lower()=='q':
#         break
#     else:
#         list1.append(float(digit))
while True:
    digit =input("Please enter several numbers in a line(q to quit): ")
    list1=digit.split()
    if list1[len(list1)-1].lower()=='q':
        list1.pop()
        break
for i in range(len(list1)):
    try:
        list1[i]=float(list1[i])
    except ValueError:
        print("Invalid input, please enter numbers only.")
        list1.pop(i)
if list1:
    print("The average is:", sum(list1)/len(list1))
