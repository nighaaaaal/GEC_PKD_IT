"""CREATE A DICTIONARY FOR A STUDENT WITH KEYS: "name","age", and "marks"
    ~PRINT THE STUDENT'S NAME
    ~UPDATE THE AGE TO 22
    ~ADD A NEW KEY "course" with the value "cs"
    ~REMOVE THE KEY "marks" FROM THE DICTIONARY
    ~DISPLAY ALL THE KEYS, VALUES AND ITEMS FROM THE DICTIONARY USING BUILT-IN FUNCTIONS
    ~COPYING AND UPDATING DICTIONARIES
"""

student={
    "name":"Nihal",
    "age":20,
    "marks":40
}
print(f"The student name is: {student["name"]}")
student["age"]=22
print(f"Updated student age is: {student["age"]}")
student["course"]="cs"
print(f"The added course is: {student["course"]}\n")
student.pop("marks")
print(f"The keys are: {student.keys()}")
print(f"The values are: {student.values()}")
print(f"The items are: {student.items()}\n")

cp=student.copy()
cp.update({"year":"second"})
print(f"Copied and updated dictionary: {cp}")