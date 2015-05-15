#include <stdio.h>
#include <math.h>

class Rownanie {
    int a, b, c;
    float x1r, x1n, x2r, x2n, d;
    void oblicz_d();
    void wyswietl_wspolczynnik(int, int);
public:
    Rownanie();
    Rownanie(int, int, int);
    ~Rownanie();
    void pobierz_dane();
    void formatuj_rownanie();
    void oblicz_pierwiastki();
    void wyswietl_wynik();
};

int main(){
    Rownanie r;
    r.pobierz_dane();
    r.formatuj_rownanie();
    r.oblicz_pierwiastki();
    r.wyswietl_wynik();

    return 0;
}

Rownanie::Rownanie(int a_, int b_, int c_){
    a = a_;
    b = b_;
    c = c_;
}

void Rownanie::pobierz_dane(){
    scanf("%d %d %d", &a, &b, &c);
}

void Rownanie::wyswietl_wspolczynnik(int x, int first){
    if (x != 0){
        if (x == -1){
            printf("-");
        } else if (x != 1){
            if ((first == 0) && (x > 0))
                printf("+ ");
            printf("%d", x);
        } else if ((first == 0) && (x == 1)){
            printf("+ ");
        }
    }
}

void Rownanie::formatuj_rownanie(){
    int first = 1;
    if (a != 0){
        wyswietl_wspolczynnik(a, first);
        printf("xx ");
        first = 0;
    }

    if (b != 0){
        wyswietl_wspolczynnik(b, first);
        printf("x ");
        first = 0;
    }

    if ((a == 0) && (b == 0)){
        printf("%d", c);
    } else if (c != 0){
        wyswietl_wspolczynnik(c, first);
        if (c == 1)
            printf("%d", c);
    }

    printf(" = 0\n");
}

void Rownanie::oblicz_pierwiastki(){
    if (a != 0){
        oblicz_d();

        if (d > 0){
            x1r = (-b-sqrt(d))/(2*a);
            x2r = (-b+sqrt(d))/(2*a);
        } else if (d == 0){
            x1r = (-b)/(2*a);
        } else {
            x1r = (float)(-b)/(2*a);
            x1n = (-sqrt(fabs(d)))/(2*a);
            x2r = -(x1r);
            x2n = -(x1n);
        }
    } else {
        printf("To nie rownanie kwadratowe\n");
    }
}

void Rownanie::oblicz_d(){
    d = b*b - 4*a*c;
}

void Rownanie::wyswietl_wynik(){
    if(a != 0){
        printf("Pierwiastki równania to:\n");

        if (d > 0){
            printf("x1 = %f\nx2 = %f\n", x1r, x2r);
        } else if (d == 0){
            printf("x1 = %f\n", x1r);
        } else {
            printf("x1r = %f, x1n = %f\nx2r = %f, x2n = %f\n", x1r, x1n, x2r, x2n);
        }
    } else {
        printf("To nie jest rownanie kwadratowe\n");
    }
}

Rownanie::Rownanie(){};

Rownanie::~Rownanie(){};
