# ---------------------------------
# Markus Dwiyanto Tobi Sogen
# CS50 for teachers
# Indonesia
# mario-more.py
# ---------------------------------
# TODO
from cs50 import get_int
# cek if user input number true or false
while True:
    height = get_int("Height:  ")
    # try check number input from user
    if height > 0 and height < 9:
        break

for i in range(height):
        # Print the left side
        for j in range(height - i - 1):
            print(" ", end="")
        for j in range(i + 1):
            print("#", end="")
        # Print space
        print("  ", end="")
        # Print the right side
        for j in range(i + 1):
            print("#", end="")
        print()