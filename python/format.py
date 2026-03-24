# dict1={"Leo":"123.2542","Jack":"124.2525","Tom":"145.252521"}
# for name , score in dict1.items():
#     print("{0}'s score is {1:.2f}".format(name,float(score)))
    
dict1={"Leo":"123.2542","Jack":"124.2525","Tom":"145.252521"}
for name , score in dict1.items():
    print(f"{name}'s score is {float(score):.2f}")