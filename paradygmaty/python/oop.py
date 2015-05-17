#!/usr/bin/python3
import math

class Equantion:
    'Klasa równania'

    def __init__(self, a = 0, b = 0, c = 0):
        self.a = a
        self.b = b
        self.c = c
        self.roots()

    def input(self):
        print("Podaj dane")
        self.a = int(input("a = "))
        self.b = int(input("b = "))
        self.c = int(input("c = "))
        self.roots()

    def print(self):
        if self.a != 0:
            print("{:d}xx ".format(self.a), end="")
    
        if self.b != 0:
            print("{:+d}x ".format(self.b), end="")
    
        if self.c != 0:
            print("{:+d} ".format(self.c), end="")
    
        if (self.a == 0) and (self.b == 0) and (self.c == 0):
            print("0 ", end="")
    
        print("= 0")

    def roots(self):
        self.calc_d()

        if self.a != 0:
            if self.d > 0:
                self.x1r = (-self.b-math.sqrt(self.d))/(2*self.a)
                self.x2r = (-self.b+math.sqrt(self.d))/(2*self.a)
            elif self.d == 0:
                self.x1r = (-self.b)/(2*self.a)
            else:
                self.x1r = (-self.b)/(2*self.a)
                self.x1n = (-math.sqrt(math.fabs(self.d)))/(2*self.a)
                self.x2r = -self.x1r
                self.x2n = -self.x1n

    def calc_d(self):
        self.d = self.b**2 - 4*self.a*self.c

    def solution(self):
        if self.a != 0:
            if self.d > 0:
                print("x1 = %s x2 = %s" % (self.x1r, self.x2r))
            elif (self.d == 0) and (self.a != 0):
                print("x1 = %s" % (self.x1r))
            elif self.d < 0:
                print("x1r = %s x1n = %s x2r = %s x2n = %s" % (self.x1r, self.x1n, self.x2r, self.x2n))
        else:
            print("to nie równanie kwadratowe!")

if __name__ == "__main__":
    r = Equantion()
    r.input()
    r.print()
    r.solution()

    r1 = Equantion(1,1,1)
    r1.print()
    r1.solution()

    r2 = Equantion(1,4,1)
    r2.print()
    r2.solution()
