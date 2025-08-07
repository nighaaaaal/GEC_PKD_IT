def find_most_frequent(numbers_list):
    if not numbers_list:
        return None

    counts = {}
    for number in numbers_list:
        if number in counts:
            counts[number] += 1
        else:
            counts[number] = 1
    
    most_frequent_num = None
    max_count = -1
    for number, count in counts.items():
        if count > max_count:
            max_count = count
            most_frequent_num = number
            
    return most_frequent_num


my_list = [1, 3, 7, 3, 2, 3, 7, 1, 3]
result = find_most_frequent(my_list)

print(f"The original list was: {my_list}")
print(f"The most frequent number is: {result}")