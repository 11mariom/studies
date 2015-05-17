#!/usr/bin/python3
import math

def pobierz_dane():
    print("Podaj dane")
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))

    return (a,b,c)

def formatuj_rownanie(a,b,c):
    s = ""
    if a != 0:
        print("{:d}xx ".format(a), end="")

    if b != 0:
        print("{:+d}x ".format(b), end="")

    if c != 0:
        print("{:+d} ".format(c), end="")

    if (a == 0) and (b == 0) and (c == 0):
        print("0 ", end="")

    print("= 0")

def oblicz_pierwiastki(a,b,c):
    if a != 0:
        d = oblicz_d(a,b,c)
        x1r = 0 
        x1n = 0
        x2r = 0
        x2n = 0

        if d > 0:
            x1r = (-b-math.sqrt(d))/(2*a)
            x2r = (-b+math.sqrt(d))/(2*a)
        elif d == 0:
            x1r = (-b)/(2*a)
        else:
            x1r = (-b)/(2*a)
            x1n = (-math.sqrt(math.fabs(d)))/(2*a)
            x2r = -x1r
            x2n = -x1n
            
        return (x1r, x1n, x2r, x2n)
    else:
        print("to nie równanie kwadratowe")
        return (0,0,0,0)

def oblicz_d(a,b,c):
    return b**2 - 4*a*c

def wyswietl_wynik(a,b,c,x1r,x1n,x2r,x2n):
    d = oblicz_d(a,b,c)

    if d > 0:
        print("x1 = %s x2 = %s" % (x1r, x2r))
    elif (d == 0) and (a != 0):
        print("x1 = %s" % (x1r))
    elif d < 0:
        print("x1r = %s x1n = %s x2r = %s x2n = %s" % (x1r, x1n, x2r, x2n))
    else:
        print("to nie równanie kwadratowe!")

if __name__ == "__main__":
    (a,b,c) = pobierz_dane()
    formatuj_rownanie(a,b,c)
    (x1r, x1n, x2r, x2n) = oblicz_pierwiastki(a,b,c)
    wyswietl_wynik(a,b,c,x1r,x1n,x2r,x2n)
