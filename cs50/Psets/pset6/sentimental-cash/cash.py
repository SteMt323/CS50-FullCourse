from cs50 import get_float

cantidad = int
while cantidad != 0:
    cantidad = get_float("Change: ")
    if cantidad >= 0: break
cambio = 0

while cantidad > 0:
    if cantidad >= 0.25:
        cantidad -= 0.25
    elif cantidad >= 0.10:
        cantidad -= 0.10
    elif cantidad >= 0.05:
        cantidad -= 0.05
    else:
        cantidad -= 0.01

    cantidad = round(cantidad,2)
    cambio += 1

print(cambio)
