# Experiment 11.1: Program to find total marks using multiple inheritance.

class Student:
    """
    A class to handle student details.
    """
    def __init__(self):
        self.name = ""
        self.roll_no = 0

    def accept_student_details(self):
        """Accepts the student's name and roll number."""
        self.name = input("Enter Student Name: ")
        self.roll_no = int(input("Enter Roll Number: "))

    def display_student_details(self):
        """Displays the student's name and roll number."""
        print(f"\n--- Student Details ---")
        print(f"Name: {self.name}")
        print(f"Roll Number: {self.roll_no}")

class Sports:
    """
    A class to handle sports marks.
    """
    def __init__(self):
        self.sports_marks = 0

    def accept_sports_marks(self):
        """Accepts the student's sports marks."""
        self.sports_marks = int(input("Enter Sports Marks: "))

    def display_sports_marks(self):
        """Displays the student's sports marks."""
        print(f"Sports Marks: {self.sports_marks}")

class Result(Student, Sports):
    """
    A class derived from Student and Sports to calculate total marks.
    """
    def __init__(self):
        # Initialize parent classes
        Student.__init__(self)
        Sports.__init__(self)
        self.subject_marks = []
        self.total_marks = 0

    def accept_subject_marks(self):
        """Accepts marks for three subjects."""
        print("\nEnter Marks for 3 Subjects:")
        for i in range(3):
            mark = int(input(f"Enter marks for Subject {i + 1}: "))
            self.subject_marks.append(mark)

    def calculate_total(self):
        """Calculates the total marks including sports marks."""
        self.total_marks = sum(self.subject_marks) + self.sports_marks

    def display_final_result(self):
        """Displays all details and the final calculated result."""
        # Call display methods from parent classes
        self.display_student_details()
        self.display_sports_marks()
        print(f"Subject Marks: {self.subject_marks}")
        print("-----------------------")
        print(f"Total Marks: {self.total_marks}")
        print("-----------------------")

# --- Main Program ---
if __name__ == "__main__":
    # Create an object of the derived class
    student_result = Result()

    # Call methods to get input, calculate, and display the result
    student_result.accept_student_details()
    student_result.accept_sports_marks()
    student_result.accept_subject_marks()
    student_result.calculate_total()
    student_result.display_final_result()
