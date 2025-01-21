from cs50 import get_int

altura = 0

while altura < 1 or altura > 8:

    altura = get_int("Ingrese la altura deseada: ")

for i in range(altura):
    for j in range(altura - i - 1):
        print(" ", end="")

    for s in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for s in range(i + 1):
        print("#", end="")

    print("\n", end="")
