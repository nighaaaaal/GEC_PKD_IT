"""CREATE A TUPLE WITH THE NAMES OF CITIES: Kochi, Mumbai, Kolkata, Varanasi, Mumbai, Delhi
    ~DISPLAY THE 2ND AND 4TH CITY
    ~COUNT HOW MANY TIMES "Mumbai" APPEARS IN THE TUPLE
    ~FIND AND PRINT THE TOTAL NO. OF CITIES(UNIQUE)
    ~FIND THE CITY WITH MAX. LENGTH
"""
cities=('Kochi','Mumbai','Kolkata','Varanasi','Mumbai','Delhi')
print(f"The original tuple is: {cities}\n")
print(f"The 2nd city is {cities[1]} and the 4th is {cities[3]}\n")
count=0
max=cities[0]
unique_cities=()
for a in cities:
    if(a=="Mumbai"):
        count+=1
    if(a not in unique_cities):
        unique_cities=unique_cities + (a,)
    if(len(a)>len(max)):
        max=a

print(f"Count of mumbai in tuple is: {count}\n")
print(f"The total number of unique cities is: {len(unique_cities)}\n")
print(f"The city with max. length is {max} with length {len(max)}\n")


"""OR
cities = ('Kochi', 'Mumbai', 'Kolkata', 'Varanasi', 'Mumbai', 'Delhi')

# ~DISPLAY THE 2ND AND 4TH CITY
# Indexing is the same and the most direct way.
print(f"The 2nd city is {cities[1]} and the 4th is {cities[3]}\n")

# ~COUNT HOW MANY TIMES "Mumbai" APPEARS IN THE TUPLE
# Use the built-in .count() method for tuples.
mumbai_count = cities.count('Mumbai')
print(f"Count of 'Mumbai' in tuple is: {mumbai_count}\n")

# ~FIND AND PRINT THE TOTAL NO. OF CITIES(UNIQUE)
# Convert the tuple to a set to automatically get unique items.
unique_cities_count = len(set(cities))
print(f"The total number of unique cities is: {unique_cities_count}\n")

# ~FIND THE CITY WITH MAX. LENGTH
# Use the max() function with a 'key' to specify how to compare items.
longest_city = max(cities, key=len)
print(f"The city with max. length is {longest_city} with length {len(longest_city)}\n")
"""