"""Given an input file which contains a list of names and phone numbers separated by
spaces in the following format: “Phone Number contains a 3- or 2-digit area code and
a hyphen followed by an 8-digit number”.
Find all names having phone numbers with
a 3-digit area code using regular expressions."""

import re

# Use 'with' to automatically handle closing the file
with open("S3/PYTHON LAB/EXPERIMENT_2/a/name_with_no.txt", "r") as file:
    for line in file:
        if re.search(r"\d{3}-\d{8}", line):
            print(line.strip())

# No need for file.close() when using 'with'