class Person:
    """
    A class to represent a person and calculate their BMI.
    Attributes are name, age, weight (kgs), and height (ft).
    """
    def __init__(self, name, age, weight_kg, height_ft):
        """The constructor for the Person class."""
        self.name = name
        self.age = int(age)
        self.weight_kg = float(weight_kg)
        # Convert height from feet to meters for the BMI formula
        self.height_m = float(height_ft) * 0.3048

    def get_bmi_result(self):
        """
        Calculates BMI and returns the health category as a string.
        The categories are "underweight", "healthy", or "obese".
        """
        # BMI formula: weight (kg) / [height (m)]^2
        # We handle the case where height is zero to avoid a division error.
        if self.height_m == 0:
            return "Invalid height"

        bmi = self.weight_kg / (self.height_m ** 2)
        
        print(f"\n--- Calculating for {self.name} ---")
        print(f"Your BMI Score is: {bmi:.2f}") # Display BMI rounded to 2 decimal places

        if bmi < 18.5:
            return "underweight"
        elif 18.5 <= bmi < 25:
            return "healthy"
        else: # bmi >= 25
            return "obese"

# --- Main Program Execution ---
# This block demonstrates how to use the Person class.
if __name__ == "__main__":
    print("--- BMI Calculator ---")
    
    # Get user input
    try:
        user_name = input("Enter your name: ")
        user_age = input("Enter your age: ")
        user_weight = input("Enter your weight in kilograms (kgs): ")
        user_height = input("Enter your height in feet (ft): ")

        # Create an instance of the Person class
        person1 = Person(user_name, user_age, user_weight, user_height)

        # Call the method and print the returned result
        health_status = person1.get_bmi_result()
        print(f"Health Status: {health_status}")

    except ValueError:
        print("\nError: Please enter valid numbers for age, weight, and height.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
