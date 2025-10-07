# Experiment 11.2: Program to demonstrate abstract classes and methods.

# Import the necessary components from the abc module
from abc import ABC, abstractmethod

class Shape(ABC):
    """
    An abstract base class representing a generic shape.
    It cannot be instantiated directly.
    """
    @abstractmethod
    def area(self):
        """
        An abstract method to calculate the area of the shape.
        Subclasses must provide an implementation for this method.
        """
        pass

    @abstractmethod
    def perimeter(self):
        """
        An abstract method to calculate the perimeter of the shape.
        Subclasses must provide an implementation for this method.
        """
        pass

class Rectangle(Shape):
    """
    A concrete class representing a rectangle, inheriting from Shape.
    """
    def __init__(self, width, height):
        self.width = width
        self.height = height
        print(f"Created a Rectangle with width={width}, height={height}")

    def area(self):
        """Provides a concrete implementation for the area method."""
        return self.width * self.height

    def perimeter(self):
        """Provides a concrete implementation for the perimeter method."""
        return 2 * (self.width + self.height)

class Circle(Shape):
    """
    A concrete class representing a circle, inheriting from Shape.
    """
    def __init__(self, radius):
        self.radius = radius
        print(f"\nCreated a Circle with radius={self.radius}")

    def area(self):
        """Provides a concrete implementation for the area method."""
        return 3.14159 * self.radius * self.radius

    def perimeter(self):
        """Provides a concrete implementation for the perimeter method (circumference)."""
        return 2 * 3.14159 * self.radius

# --- Main Program ---
if __name__ == "__main__":
    # Note: You cannot create an object of an abstract class.
    # The following line would raise a TypeError:
    # my_shape = Shape()
    # print("Attempting to create a Shape object will fail.")

    # Create objects of the concrete subclasses
    my_rectangle = Rectangle(10, 5)
    print(f"Area of Rectangle: {my_rectangle.area()}")
    print(f"Perimeter of Rectangle: {my_rectangle.perimeter()}")

    my_circle = Circle(7)
    print(f"Area of Circle: {my_circle.area():.2f}")
    print(f"Perimeter of Circle: {my_circle.perimeter():.2f}")
