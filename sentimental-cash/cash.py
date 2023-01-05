# TODO
from cs50 import get_float
# count coins is used
count = 0
# input user
while True:
    changeowed = get_float("Change owed: ")
    if changeowed > 0:
        break
cent = round(change * 100)
while cent >= 25:
    cent = cent - 25
    count += 1

while cent >= 10:
    cent = cent - 10
    count += 1

while cent >= 5:
    cent = cent - 5
    count += 1

while cent >= 1:
    cent = cent - 1
    count += 1



