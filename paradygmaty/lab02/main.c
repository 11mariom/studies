#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x1,x2;
} rzeczywiste;

typedef struct {
    float x1,x2;
} urojone;

typedef struct {
    int* parametry;
    float d;
    rzeczywiste *x;
    urojone *i;
} rown;

void pobierz_dane(rown *r);
void formatuj_rownanie(rown *r);
void oblicz_pierwiastki(rown *r);
void oblicz_d(rown *r);
void wyswietl_wynik(rown *r);

int main(){
    rown *r = malloc(sizeof(rown));
    r->parametry = malloc(3 * sizeof(int));
    r->x = malloc(sizeof(rzeczywiste));
    r->i = malloc(sizeof(urojone));

    pobierz_dane(r);
    
    formatuj_rownanie(r);
    if ((r->parametry[0] != 0) && (r->parametry[1] != 0)){
        oblicz_pierwiastki(r);
        wyswietl_wynik(r);
    }

    return 0;
}

void pobierz_dane(rown *r){
    scanf("%d %d %d", &r->parametry[0], &r->parametry[1], &r->parametry[2]);
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

void formatuj_rownanie(rown *r){
    int first = 1;
    if (r->parametry[0] != 0){
        wyswietl_wspolczynnik(r->parametry[0], first);
        printf("xx ");
        first = 0;
    }

    if (r->parametry[1] != 0){
        wyswietl_wspolczynnik(r->parametry[1], first);
        printf("x ");
        first = 0;
    }

    if ((r->parametry[0] == 0) && (r->parametry[1] == 0)){
        printf("%d", r->parametry[2]);
    } else if (r->parametry[2] != 0){
        wyswietl_wspolczynnik(r->parametry[2], first);
        if (r->parametry[2] == 1)
            printf("%d", r->parametry[2]);
    }

    printf(" = 0\n");
}

void oblicz_pierwiastki(rown *r){
    if (r->parametry[0] != 0){
        oblicz_d(r);
        if (r->d > 0){
            r->x->x1 = (-(r->parametry[1])-sqrt(r->d))/(2*(r->parametry[0]));
            r->x->x2 = (-(r->parametry[1])+sqrt(r->d))/(2*(r->parametry[0]));
        } else if (r->d == 0){
            r->x->x1 = (-r->parametry[1])/(2*r->parametry[0]);
        } else {
            r->x->x1 = (float)(-r->parametry[1])/(2*r->parametry[0]);
            r->i->x1 = (-sqrt(fabs(r->d)))/(2*r->parametry[0]);
            r->x->x2 = -(r->x->x1);
            r->i->x2 = -(r->i->x1);
        }
    }
}

void oblicz_d(rown *r){
    r->d = r->parametry[1]*r->parametry[1] - 4*r->parametry[0]*r->parametry[2];
}

void wyswietl_wynik(rown *r){
    printf("Pierwiastki równania to:\n");

    if (r->d > 0){
        printf("x1 = %f\nx2 = %f\n", r->x->x1, r->x->x2);
    } else if (r->d == 0){
        printf("x1 = %f\n", r->x->x1);
    } else {
        printf("x1r = %f, x1n = %f\nx2r = %f, x2n = %f\n", r->x->x1, r->i->x1, r->x->x2, r->i->x2);
    }
}
