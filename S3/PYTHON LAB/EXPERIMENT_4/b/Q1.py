# 1. Define a custom exception class
# It inherits from Python's base Exception class.
class MyError(Exception):
    pass

# ---

# 2. Use the custom exception in a try...except block
try:
    y = int(input("Enter an even number: "))
    
    # Check if the number is odd. The condition y % 2 != 0 is true for odd numbers.
    if y % 2 != 0:
        # If it's odd, manually raise our custom error with a message.
        raise MyError("Error: The number you entered is not even.")
        
except MyError as g:
    # This block catches our specific 'MyError' and prints the message.
    print(g)

else:
    # This block runs only if no exception was raised (i.e., the number was even).
    print("Success! This is an even number.")