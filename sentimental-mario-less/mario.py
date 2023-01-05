# ---------------------------------
# Markus Dwiyanto Tobi Sogen
# CS50 for teachers
# Indonesia
# mario-less.py
# ---------------------------------
# TODO
from cs50 import get_int
while True: #cek if user input number true or false
    height = get_int("Height:  ")
    # try check number input from user
    if height > 0 and height < 9:
        break
# row
for row in range(height):
    for space in range(height - row -1, 0, -1): # try make space
        print(" ", end="")
    for hash in range(row + 1): # try make hash
        print("#", end ="")
    print("\n", end ="")