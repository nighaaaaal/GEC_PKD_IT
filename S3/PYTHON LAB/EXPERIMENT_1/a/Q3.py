##CREATE A LIST OF 5 STUDENT'S NAME
##DISPLAY THE 3RD STUDENT NAME
##CHANGE THE NAME AT INDEX 1
##REMOVE THE LAST NAME USING POP()
##PRINT ALL THE NAMES USING A LOOP

names=["babu","namboori","koshi","chacko","thomman"]
print(f"The original list is: {names}\n")
print(f"The name at 3rd position is: {names[2]}\n")
names[1]="raman"
names.pop()
print("THE FINAL LIST IS:")
for a in names:
    print(a)