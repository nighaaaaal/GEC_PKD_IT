##CREATE A LIST OF EVEN NO.S FROM 1 TO 20 USING LIST COMPREHENSION

a=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
b=[x for x in a if x%2==0]
print(f"The even no.s found using list comprehension is: {b}")