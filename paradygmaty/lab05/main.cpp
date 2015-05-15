#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#include <iostream>

class Rownanie {
    std::vector<int> param;
    std::vector<std::complex<float>> wynik;
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
};

void Rownanie::pobierz_dane(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    param.push_back(a);
    param.push_back(b);
    param.push_back(c);
    wynik.reserve(2);
}

void Rownanie::wyswietl_wspolczynnik(int x, int first){
    if (x != 0){
        if (x == -1){
            std::cout << "-";
        } else if (x != 1){
            if ((first == 0) && (x > 0))
                std::cout << "+ ";
            std::cout << x;
        } else if ((first == 0) && (x == 1)){
            std::cout << "+ ";
        }
    }
}

void Rownanie::formatuj_rownanie(){
    int first = 1;
    if (param[0] != 0){
        wyswietl_wspolczynnik(param[0], first);
        std::cout << "xx ";
        first = 0;
    }

    if (param[1] != 0){
        wyswietl_wspolczynnik(param[1], first);
        std::cout << "x ";
        first = 0;
    }

    if ((param[0] == 0) && (param[1] == 0)){
        std::cout << param[2];
    } else if (param[2] != 0){
        wyswietl_wspolczynnik(param[2], first);
        if (param[2] == 1)
            std::cout << param[2];
    }

    std::cout << " = 0" << std::endl;
}

void Rownanie::oblicz_pierwiastki(){
    std::cout << "wynik: size = " << wynik.size() << "; capacity = " 
        << wynik.capacity() << std::endl; 
    if (param[0] != 0){
        oblicz_d();

        if (d > 0){
            wynik.push_back( (-param[1]-sqrt(d))/(2*param[0]) );
            wynik.push_back( (-param[1]+sqrt(d))/(2*param[0]) );
        } else if (d == 0){
            wynik.push_back( (-param[1])/(2*param[0]) );
        } else {
            wynik.push_back( (float)(-param[1])/(2*param[0]) + 1i *  (-sqrt(fabs(d)))/(2*param[0]) );
            wynik.push_back( - wynik.at(0) );
        }
    } else {
        std::cout << "To nie rownanie kwadratowe" << std::endl;
    }
    wynik.shrink_to_fit();
}

void Rownanie::oblicz_d(){
    d = param[1]*param[1] - 4*param[0]*param[2];
}

void Rownanie::wyswietl_wynik(){
    std::cout << "wynik: size = " << wynik.size() << "; capacity = " 
        << wynik.capacity() << std::endl; 
    if(param[0] != 0){
        std::cout << "Pierwiastki równania to:" << std::endl;
        if (d > 0){
            std::cout << "x1 = " << wynik.front() << " x2 = " << wynik.back() << std::endl;
        } else if (d == 0){
            std::cout << "x1 = " << wynik.front() << std::endl;
        } else {
            std::cout << "x1r = " << wynik[0].real() << " x1n = " << wynik[0].imag()
                << " x2r = " << wynik[1].real() << " x2n = " << wynik[1].imag() << std::endl;
            
            std::cout << "x1 = " << wynik[0] << " x2 = " << wynik[1] << std::endl << std::endl;
            
            std::cout << "|x1| = " << std::abs(wynik[0])
                << " |x2| = " << std::abs(wynik[1]) << std::endl;
            std::cout << "sin(x2) = " << std::sin(wynik[1]) << " cos(x2) = " 
                << std::cos(wynik[1]) << std::endl;

            std::cout << "x1 + x2 = " << wynik[0] + wynik[1] << std::endl
                << "x1 - x2 = " << wynik[0] - wynik[1] << std::endl
                << "x1 * x2 = " << wynik[0] * wynik[1] << std::endl;

        }
    } else {
        std::cout << "To nie jest równanie kwadratowe" << std::endl;
    }
}

Rownanie::Rownanie(){};

