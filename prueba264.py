while True:    
    reps = int(input("iteraciones: "))
    a = int(input("BASE: "))
    b = a
    for i in range(reps - 1):
        b -= 1
        a += b
    print("Resultado:", a)