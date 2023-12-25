def basesqrt10(n):
    a = str(n)
    out = ""
    ii = 0
    pos = 0
    while pos < len(a):
        print(ii)
        if ii%2 == 0:
            out += a[pos]
            pos += 1
        else:
            out += "0"
        ii += 1
    return int(out)
prueba = (9, 98, 987, 79)

for _ in prueba:
    print(basesqrt10(_))