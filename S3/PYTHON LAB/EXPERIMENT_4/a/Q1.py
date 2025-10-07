x = [1, 2, 3, 4, 5, 0]
print(f"The list is: {x}")

try:
    # Get integer input from the user for the indices
    a = int(input("Enter numerator index (1-6): "))
    b = int(input("Enter denominator index (1-6): "))

    # Perform the calculation using list elements
    numerator = x[a - 1]
    denominator = x[b - 1]
    c = numerator / denominator

except ValueError:
    # Runs if the input is not a whole number
    print("Error: Invalid input. You must enter a whole number.")

except IndexError:
    # Runs if the index is outside the list's range
    print("Error: Index out of range. Please enter a number between 1 and 6.")

except ZeroDivisionError:
    # Runs if the chosen denominator is 0
    print("Error: Cannot divide by zero.")

else:
    # Runs ONLY if no exceptions occurred
    print(f"Result: {numerator} / {denominator} = {c}")

finally:
    # Runs ALWAYS, whether an exception occurred or not
    print("Thank you!")