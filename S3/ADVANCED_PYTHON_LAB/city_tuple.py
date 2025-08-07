cities=('kochi','mumbai','kolkata','varanasi','mumbai','delhi')
print(f"The 2nd city is {cities[1]}")
print(f"The 4th city is {cities[3]}")
l=len(cities)
count=0
max=cities[0]
for i in range(l):
    if(cities[i]=='mumbai'):
        count+=1
    if(len(cities[i])>len(max)):
        max=cities[i]
print(f"Mumbai appears {count} times")
print(f"The city with max.length is {max}")