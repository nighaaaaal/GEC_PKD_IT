import sqlite3

# 1. Connect to the database
conn = sqlite3.connect('college.db')

# 2. Create a cursor object
cursor = conn.cursor()

# --- CREATE ---
# 3. Create a table named STUDENT if it doesn't already exist
create_table_query = """
CREATE TABLE IF NOT EXISTS STUDENT (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    rollno INTEGER UNIQUE NOT NULL
);
"""
cursor.execute(create_table_query)

# --- INSERT (part of CREATE) ---
# 4. Insert data directly into the SQL string
print("Inserting initial data...")
cursor.execute("INSERT INTO STUDENT (name, rollno) VALUES ('NIHAL', 1)")
cursor.execute("INSERT INTO STUDENT (name, rollno) VALUES ('BABU', 2)")
conn.commit() # Save the changes

# --- UPDATE ---
# 5. Update an existing record
print("Updating BABU's roll number...")
cursor.execute("UPDATE STUDENT SET rollno = 6 WHERE name = 'BABU'")
conn.commit() # Save the change

# --- DELETE ---
# 6. Delete a record from the table
print("Deleting student with roll number 1...")
cursor.execute("DELETE FROM STUDENT WHERE rollno = 1")
conn.commit() # Save the change

# --- READ ---
# 7. Select and display all remaining records
print("\nFetching final records from the database:")
cursor.execute("SELECT * FROM STUDENT")

all_rows = cursor.fetchall()
for row in all_rows:
    print(row)

# 8. Close the connection
conn.close()