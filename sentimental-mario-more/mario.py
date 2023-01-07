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
    # Print the left-hand pyramid
    for j in range(i + 1):
        print("#", end="")
    # Print the space in between the pyramids
    print("  ", end="")
    # Print the right-hand pyramid
    for j in range(i + 1):
        print("#", end="")
    print()