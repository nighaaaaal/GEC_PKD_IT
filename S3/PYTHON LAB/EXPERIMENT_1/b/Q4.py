##CREATE A 2D LIST (MATRIX) OF 3 ROWS AND 4 COLUMNS USING NESTED LIST COMPREHENSION.
##EACH ELEMENT SHOULD BE ITS ROW MULTIPLIED BY COLUMN NUMBER

matrix=[[x*y for y in range(4)] for x in range(3)]
print(f"The matrix is:\n")
for i in range(3):
    for j in range(4):
        print(matrix[i][j],end=",")
    print()

##EXPLANATION CODE
##matrix = []
"""for x in range(3):  # <-- This one starts first
    inner_list = []
    for y in range(4):  # <-- This one runs completely for each x
        inner_list.append(x * y)
    matrix.append(inner_list)#
print(matrix)"""