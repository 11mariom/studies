#include <stdio.h>
#include <math.h>

void pobierz_dane(int* a, int* b, int* c);
void formatuj_rownanie(int a, int b, int c);
void oblicz_pierwiastki(int a, int b, int c,
                        float* x1r, float* x1n, float* x2r, float* x2n);
float oblicz_d(int a, int b, int c);
void wyswietl_wynik(int a, int b, int c,
                    float x1r, float x1n, float x2r, float x2n);

int main(){
    int a, b, c;
    float x1r, x1n, x2r, x2n;

    pobierz_dane(&a, &b, &c);
    formatuj_rownanie(a, b, c);
    if ((a != 0) && (b != 0)){
        oblicz_pierwiastki(a, b, c, &x1r, &x1n, &x2r, &x2n);
        wyswietl_wynik(a, b, c, x1r, x1n, x2r, x2n);
    }

    return 0;
}

void pobierz_dane(int* a, int* b, int* c){
    scanf("%d %d %d", a, b, c);
}

void wyswietl_wspolczynnik(int a, int first){
    if (a != 0){
        if (a == -1){
            printf("-");
        } else if (a != 1){
            if ((first == 0) && (a > 0))
                printf("+ ");
            printf("%d", a);
        } else if ((first == 0) && (a == 1)){
            printf("+ ");
        }
    }
}

void formatuj_rownanie(int a, int b, int c){
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
    }

    printf(" = 0\n");
}

void oblicz_pierwiastki(int a, int b, int c,
                        float* x1r, float* x1n, float* x2r, float* x2n){
    if (a != 0){
        float d = oblicz_d(a, b, c);

        if (d > 0){
            *x1r = (-b-sqrt(d))/(2*a);
            *x2r = (-b+sqrt(d))/(2*a);
        } else if (d == 0){
            *x1r = (-b)/(2*a);
        } else {
            *x1r = (float)(-b)/(2*a);
            *x1n = (-sqrt(fabs(d)))/(2*a);
            *x2r = -(*x1r);
            *x2n = -(*x1n);
        }
    }
}

float oblicz_d(int a, int b, int c){
    return b*b - 4*a*c;
}

void wyswietl_wynik(int a, int b, int c,
                    float x1r, float x1n, float x2r, float x2n){
    float d = oblicz_d(a, b, c);

    printf("Pierwiastki równania to:\n");

    if (d > 0){
        printf("x1 = %f\nx2 = %f\n", x1r, x2r);
    } else if (d == 0){
        printf("x1 = %f\n", x1r);
    } else {
        printf("x1r = %f, x1n = %f\nx2r = %f, x2n = %f\n", x1r, x1n, x2r, x2n);
    }
}
