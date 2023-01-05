# TODO
from cs50 import get_string

count_letter = 0
count_word = 1
count_sentence = 0

# Get input from user
text = get_string("Text: ")
textl = len(text)

# cek number of letters in text
for i in range(textl):
    if text[i].isalpha():
        count_letter += 1
# try cek number of words in text input
    elif text[i].isspace():
        count_word += 1
# try cek number of sentence
    elif text[i] == ',' or text[i] == '?' or text[i] == '!' :
        count_sentence += 1

# Coleman-Liau index Formula
calcu = (0.0588 * count_letter / count_word * 100) - (0.296 * count_sentence / count_word * 100) - 15.8
index = round(calcu)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")