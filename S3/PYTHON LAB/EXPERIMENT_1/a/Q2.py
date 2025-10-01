##CREATE A LIST OF NUMBERS FROM 10 TO 20
##SLICE AND PRINT THE SUBLIST FROM INNDEX 2 TO 6
##FIND AND PRINT THE LENGTH OF THE LIST
##CHECK IF THE NUMBER 15 IS PRESENT IN THE LIST
##SORT THE LIST IN DESCENDING ORDER

l=[10,11,12,13,14,15,16,17,18,19,20]
print(f"The original list is {l}\n")
print(f"The sliced sublist from 2 to 6th index {l[2:7]}\n")
print(f"The length of the list is {len(l)}\n")
x = 15 in l
print(f"IS 15 IN LIST (TRUE OR FALSE): {x}\n")
l.reverse()
print(f"The list after reversing is: {l}\n")