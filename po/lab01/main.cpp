#include <iostream>

using namespace std;

struct Osoba 
{
    int wiek;
    int wzrost;
    int waga;
};

void setOsoba(Osoba &o, int wiek, int waga);
void printOsoba(Osoba o);

//createOsoba(Osoba *o);
void setOsoba(Osoba *o, int wiek, int waga);
void printOsoba(Osoba *o);
void deleteOsoba(Osoba *o);

int main()
{
    Osoba objOsoba;
    setOsoba(objOsoba, 1, 4);
    printOsoba(objOsoba);

    Osoba *pOsoba;
    pOsoba = new Osoba;
    //createOsoba(pOsoba);
    setOsoba(pOsoba, 2, 5);
    printOsoba(pOsoba);
    deleteOsoba(pOsoba);
    
    Osoba *arrOsoba = new Osoba[10];
    
    for(int i = 0; i < 10; ++i){
	setOsoba(arrOsoba[i], i, 2 * i);
	
    }

    Osoba **arrPtrOsoba = new Osoba*[10];
    
    for(int i = 0; i < 10; ++i){
	arrPtrOsoba[i] = new Osoba;
    }

    return 0;
}

void setOsoba(Osoba &o, int wiek, int waga)
{
    o.wiek = wiek;
    o.waga = waga;
}

void printOsoba(Osoba o)
{
    cout << "wiek = " << o.wiek << endl
	 << "waga = " << o.waga << endl;
}

void setOsoba(Osoba *o, int wiek, int waga)
{
    o->wiek = wiek;
    o->waga = waga;
}

void printOsoba(Osoba *o)
{
    cout << "wiek = " << o->wiek << endl
	 << "waga = " << o->waga << endl;
}

void deleteOsoba(Osoba *o)
{
    delete o;
}
