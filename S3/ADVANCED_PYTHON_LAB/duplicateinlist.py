list=[2,5,6,24,5,6,2,6,0]
seen_num=set()
for i in list:
    if i in seen_num:
        print("DUPLICATE FOUND")
        break
    else:
        seen_num.add(i)