class Vector2D:
    """
    A simple class representing a 2D vector to demonstrate operator overloading.
    It has two attributes: x and y.
    """
    def __init__(self, x, y):
        """The constructor for the Vector2D class."""
        self.x = x
        self.y = y

    def __add__(self, other):
        """
        Overloads the '+' operator to add two Vector2D objects.
        This special method is called when you use the '+' symbol
        between two instances of this class.
        """
        # Create and return a new Vector2D object with the summed components.
        return Vector2D(self.x + other.x, self.y + other.y)

    def __str__(self):
        """
        Provides a user-friendly string representation of the object.
        This special method is called when you use print() on an object.
        """
        return f"Vector({self.x}, {self.y})"

# --- Main Program Execution ---
# This block demonstrates the operator overloading in action.
if __name__ == "__main__":
    print("--- Operator Overloading Demonstration ---")
    
    # Create two instances of the Vector2D class
    v1 = Vector2D(3, 5)
    v2 = Vector2D(10, 2)
    
    # Use the '+' operator on the objects.
    # Behind the scenes, Python calls v1.__add__(v2).
    result_vector = v1 + v2
    
    print(f"Vector 1: {v1}")
    print(f"Vector 2: {v2}")
    print(f"Result of v1 + v2: {result_vector}")
