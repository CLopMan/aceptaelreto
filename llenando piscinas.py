import sys
from math import ceil
def competicion_piscina(matrix):
    resultado = ""
    for valores in matrix:
        resultado += _competicion_piscina(valores) + "\n"
    return resultado

def _competicion_piscina(valores):
    if valores[0] <= valores[1]:
        viajesA = 1
    else:
        viajesA = 1 + (valores[0] - valores[1]) / (valores[1] - valores[2])

    if valores[3] <= valores[4]:
        viajesB = 1
    else:
        viajesB = 1 + (valores[3] - valores[4]) / (valores[4] - valores[5])
     #print(viajesA, viajesB)
    viajesA, viajesB = ceil(viajesA), ceil(viajesB) #O(1)

    if viajesA <= 0:
        viajesA = sys.maxsize
    if viajesB <= 0:
        viajesB = sys.maxsize
    print(viajesA, viajesB)
    if viajesA < viajesB:
        return "Yo:" + str(viajesA)
    elif viajesB < viajesA:
        return "vecino:" + str(viajesB)
    else:
        return "Empate:" + str(viajesA)




prueba = [1, 41,7]
def simulacion(lista):
    viajes = 0
    caudal = 0
    while caudal < lista[0]:
        if caudal > 0:
            caudal -= lista[2]
        viajes += 1
        caudal += lista[1]
        print(viajes, caudal)
    print(1 + (lista[0] - lista[1]) / (lista[1] - lista[2]))

# simulacion(prueba)

casos = [[10, 5, 1, 15, 6, 1],
[50, 5, 1, 50, 5, 0],
[50, 5, 1, 50, 5, 6]]

print(competicion_piscina(casos)),

