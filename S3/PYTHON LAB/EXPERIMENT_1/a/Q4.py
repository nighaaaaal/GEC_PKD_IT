##INPUT 10 NUMBERS FROM THE USER AND STORE IT IN A LIST
##COUNT HOW MANY ARE EVEN
##COUNT HOW MANY ARE GREATER THAN 50
##PRINT ONLY ODD NUMBER FROM THE LIST

numbers=[]
for i in range(10):
    num=int(input(f"ENTER {i+1}th number: "))
    numbers.append(num)
print(f"The original list is: {numbers}")
even=0
greater_than_50=0
for num in numbers:
    if num%2==0:
        even+=1
    if num>50:
        greater_than_50+=1
print(f"Total even numbers in the list is: {even}\n")
print(f"Total numbers >50 in the list is: {greater_than_50}\n")
print(f"ODD NUMBERS IN THE LIST IS: ")
for num in numbers:
    if num%2!=0:
        print(num)

