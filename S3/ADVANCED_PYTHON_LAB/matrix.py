matrix=[[x*y for y in range(4)] for x in range(3)]
for i in range(3):
    for j in range(4):
        print(matrix[i][j],end=" ")
    print()