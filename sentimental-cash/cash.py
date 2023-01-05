# ---------------------------------
# Markus Dwiyanto Tobi Sogen
# CS50 for teachers
# Indonesia
# cash.py
# ---------------------------------
# TODO
from cs50 import get_float
# count coins is used
count = 0
# input user
while True:
    changeowed = get_float("Change owed: ")
    if changeowed > 0:
        break
cent = round(changeowed * 100)
# number of quarters
while cent >= 25:
    cent = cent - 25
    count += 1

# number of dimes
while cent >= 10:
    cent = cent - 10
    count += 1

# number of nickels
while cent >= 5:
    cent = cent - 5
    count += 1

# number of pennies
while cent >= 1:
    cent = cent - 1
    count += 1

# print number count
print(count)