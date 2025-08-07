student={
    "name":"Nihal",
    "age":19,
    "marks":40
}
print(f"Student name is {student["name"]}")
student["age"]=20
print(f"Updated student age is {student["age"]}")
student["course"]="cs"
print(f"The added course is {student["course"]}")
student.pop("marks")
print(f"The keys are:{student.keys()}")
print(f"The items are:{student.items()}")
print(f"The values are:{student.values()}")
cp=student.copy()
cp.update({"year":"second"})
print(f"Copied and updated dictionary:{cp}")
