##FROM A LIST OF WORDS, CREATE A NEW LIST CONTAINING ONLY THE WORDS THAT STARTS WITH "b"

a=['banana','apple','carrot','brinjal','beetroot']
print(f"The original list is: {a}\n")
b=[x for x in a if x[0]=='b']
print(f"The list which starts with 'b' is: {b}\n")