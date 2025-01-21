from cs50 import get_string


text = get_string("Text: ")

letters = sum(c.isalpha() for c in text)
words = len(text.split())
#El método len toma un objeto como parámetro y te da su longitud como valor de retorno.
#El método split divide una cadena en una lista en Python, dado un delimitador especificado.
sentences = sum(text.count(c) for c in ['.', '?', '!'])

L = (letters / words) * 100
S = (sentences / words) * 100
grade = 0.0588 * L - 0.296 * S - 15.8

if grade <= 0:
    print("Before Grade 1")
elif grade >= 1 and grade <= 16:
    print(f"Grade {round(grade)}")
elif grade > 16:
    print("Grade 16+")
