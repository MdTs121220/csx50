# ---------------------------------
# Markus Dwiyanto Tobi Sogen
# CS50 for teachers
# Indonesia
# mario-less.py
# ---------------------------------
# TODO
from cs50 import get_int
# cek if user input number true or false
while True:
    height = get_int("Height:  ")
    # try check number input from user
    if height > 0 and height < 9:
        break
# row
for row in range(height):
    # try make space
    for space in range(height - row - 1, 0, -1):
        print(" ", end="")
    # try make hash
    for hash in range(row + 1):
        print("#", end="")
    print("\n", end="")