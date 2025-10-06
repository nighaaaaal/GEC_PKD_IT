import pickle
import os

# Define the filename to be used
FILENAME = "book.dat"

def add_record():
    """Prompts the user for book details and appends them to the binary file."""
    try:
        with open(FILENAME, "ab") as f:
            book_no = int(input("Enter Book Number: "))
            book_name = input("Enter Book Name: ")
            author = input("Enter Author Name: ")
            price = float(input("Enter Price: "))
            
            record = [book_no, book_name, author, price]
            pickle.dump(record, f)
            print("✅ Record added successfully!")
            
    except ValueError:
        print("❌ Invalid input. Please enter correct data types.")
    except Exception as e:
        print(f"An error occurred: {e}")

def display_records():
    """Reads and displays all records from the binary file."""
    try:
        with open(FILENAME, "rb") as f:
            print("\n--- All Book Records ---")
            print(f"{'Book No.':<10} {'Book Name':<30} {'Author':<25} {'Price':<10}")
            print("-" * 75)
            
            while True:
                try:
                    record = pickle.load(f)
                    print(f"{record[0]:<10} {record[1]:<30} {record[2]:<25} {record[3]:<10.2f}")
                except EOFError:
                    # End of file reached
                    break
            print("-" * 75)

    except FileNotFoundError:
        print("File not found. Please add a record first.")
    except Exception as e:
        print(f"An error occurred: {e}")

def books_by_author():
    """Searches for and displays books by a specific author."""
    try:
        author_name = input("Enter the author's name to search for: ")
        found = False
        with open(FILENAME, "rb") as f:
            print(f"\n--- Books by {author_name} ---")
            print(f"{'Book No.':<10} {'Book Name':<30} {'Author':<25} {'Price':<10}")
            print("-" * 75)
            
            while True:
                try:
                    record = pickle.load(f)
                    if record[2].lower() == author_name.lower():
                        print(f"{record[0]:<10} {record[1]:<30} {record[2]:<25} {record[3]:<10.2f}")
                        found = True
                except EOFError:
                    break
            print("-" * 75)
            
            if not found:
                print(f"No books found by author '{author_name}'.")

    except FileNotFoundError:
        print("File not found. Please add a record first.")
    except Exception as e:
        print(f"An error occurred: {e}")

def books_by_price(max_price):
    """Searches for and displays books below a certain price."""
    try:
        found = False
        with open(FILENAME, "rb") as f:
            print(f"\n--- Books Cheaper Than ${max_price:.2f} ---")
            print(f"{'Book No.':<10} {'Book Name':<30} {'Author':<25} {'Price':<10}")
            print("-" * 75)
            
            while True:
                try:
                    record = pickle.load(f)
                    if record[3] < max_price:
                        print(f"{record[0]:<10} {record[1]:<30} {record[2]:<25} {record[3]:<10.2f}")
                        found = True
                except EOFError:
                    break
            print("-" * 75)

            if not found:
                print(f"No books found cheaper than ${max_price:.2f}.")

    except FileNotFoundError:
        print("File not found. Please add a record first.")
    except Exception as e:
        print(f"An error occurred: {e}")

def copy_data():
    """Copies books with price > 500 to a new file and returns the count."""
    try:
        count = 0
        costly_filename = "costly_book.dat"
        with open(FILENAME, "rb") as f_in, open(costly_filename, "wb") as f_out:
            while True:
                try:
                    record = pickle.load(f_in)
                    if record[3] > 500:
                        pickle.dump(record, f_out)
                        count += 1
                except EOFError:
                    break
        print(f"✅ Copied {count} records to '{costly_filename}'.")
        return count
    except FileNotFoundError:
        print("Source file 'book.dat' not found.")
        return 0
    except Exception as e:
        print(f"An error occurred: {e}")
        return 0

def delete_record(book_number):
    """Deletes a record with the given book number."""
    found = False
    try:
        with open(FILENAME, "rb") as f_in, open("temp.dat", "wb") as f_out:
            while True:
                try:
                    record = pickle.load(f_in)
                    if record[0] == book_number:
                        found = True # Mark as found, but don't write to temp file
                    else:
                        pickle.dump(record, f_out)
                except EOFError:
                    break
        
        # Replace the original file with the temporary one
        os.remove(FILENAME)
        os.rename("temp.dat", FILENAME)
        
        if found:
            print(f"✅ Record with Book Number {book_number} has been deleted.")
        else:
            print(f"❌ Record with Book Number {book_number} not found.")

    except FileNotFoundError:
        print("File not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


def update_record(book_number):
    """Updates the details of a record with the given book number."""
    found = False
    try:
        with open(FILENAME, "rb") as f_in, open("temp.dat", "wb") as f_out:
            while True:
                try:
                    record = pickle.load(f_in)
                    if record[0] == book_number:
                        found = True
                        print("\n--- Record Found. Enter new details ---")
                        record[1] = input(f"Enter new Book Name (current: {record[1]}): ")
                        record[2] = input(f"Enter new Author (current: {record[2]}): ")
                        record[3] = float(input(f"Enter new Price (current: {record[3]}): "))
                    
                    pickle.dump(record, f_out)
                except EOFError:
                    break
        
        os.remove(FILENAME)
        os.rename("temp.dat", FILENAME)
        
        if found:
            print(f"✅ Record with Book Number {book_number} has been updated.")
        else:
            print(f"❌ Record with Book Number {book_number} not found.")
            
    except FileNotFoundError:
        print("File not found.")
    except ValueError:
        print("❌ Invalid input for price.")
    except Exception as e:
        print(f"An error occurred: {e}")


def main_menu():
    """Displays the main menu and handles user choices."""
    while True:
        print("\n📚 Book Management System 📚")
        print("1. Add a New Book Record")
        print("2. Display All Book Records")
        print("3. Search Books by Author")
        print("4. Search Books by Price")
        print("5. Copy Costly Books (Price > 500)")
        print("6. Delete a Book Record")
        print("7. Update a Book Record")
        print("0. Exit")
        
        choice = input("Enter your choice (0-7): ")

        if choice == '1':
            add_record()
        elif choice == '2':
            display_records()
        elif choice == '3':
            books_by_author()
        elif choice == '4':
            try:
                price_limit = float(input("Enter the maximum price: "))
                books_by_price(price_limit)
            except ValueError:
                print("Invalid price entered.")
        elif choice == '5':
            copy_data()
        elif choice == '6':
            try:
                book_num = int(input("Enter Book Number to delete: "))
                delete_record(book_num)
            except ValueError:
                print("Invalid Book Number.")
        elif choice == '7':
            try:
                book_num = int(input("Enter Book Number to update: "))
                update_record(book_num)
            except ValueError:
                print("Invalid Book Number.")
        elif choice == '0':
            print("Thank you for using the system. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

# Run the main menu when the script is executed
if __name__ == "__main__":
    main_menu()