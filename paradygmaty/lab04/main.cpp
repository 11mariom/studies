#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>

class Rownanie {
    std::vector<int> param;
    std::vector<float> wynik;
    float d;
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
    param.push_back(a_);
    param.push_back(b_);
    param.push_back(c_);
}

Rownanie::~Rownanie(){
    param.clear();
    wynik.clear();
};

void Rownanie::pobierz_dane(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    param.push_back(a);
    param.push_back(b);
    param.push_back(c);
    wynik.reserve(4);
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
    if (param[0] != 0){
        wyswietl_wspolczynnik(param[0], first);
        printf("xx ");
        first = 0;
    }

    if (param[1] != 0){
        wyswietl_wspolczynnik(param[1], first);
        printf("x ");
        first = 0;
    }

    if ((param[0] == 0) && (param[1] == 0)){
        printf("%d", param[2]);
    } else if (param[2] != 0){
        wyswietl_wspolczynnik(param[2], first);
        if (param[2] == 1)
            printf("%d", param[2]);
    }

    printf(" = 0\n");
}

void Rownanie::oblicz_pierwiastki(){
    std::cout << "wynik: size = " << wynik.size() <<
        "; capacity = " << wynik.capacity() << std::endl;
    if (param[0] != 0){
        oblicz_d();

        if (d > 0){
            wynik.push_back( (-param[1]-sqrt(d))/(2*param[0]) );
            wynik.push_back( (-param[1]+sqrt(d))/(2*param[0]) );
        } else if (d == 0){
            wynik.push_back( (-param[1])/(2*param[0]) );
        } else {
            wynik.push_back( (float)(-param[1])/(2*param[0]) );
            wynik.push_back( (-sqrt(fabs(d)))/(2*param[0]) );
            wynik.push_back( -(wynik[0]) );
            wynik.push_back( -(wynik[1]) );
        }
    } else {
        printf("To nie rownanie kwadratowe\n");
    }
    wynik.shrink_to_fit();
}

void Rownanie::oblicz_d(){
    d = param[1]*param[1] - 4*param[0]*param[2];
}

void Rownanie::wyswietl_wynik(){
    if(param[0] != 0){
        printf("Pierwiastki równania to:\n");

        if (d > 0){
            printf("x1 = %f\nx2 = %f\n", wynik.front(), wynik.back());
        } else if (d == 0){
            printf("x1 = %f\n", wynik.at(0));
        } else {
            printf("x1r = %f, x1n = %f\nx2r = %f, x2n = %f\n", wynik.front(), wynik[1], wynik[2], wynik.back());
        }
    } else {
        printf("To nie jest rownanie kwadratowe\n");
    }

    std::cout << "wynik: size = " << wynik.size() <<
        "; capacity = " << wynik.capacity() << std::endl;
}

Rownanie::Rownanie(){};

