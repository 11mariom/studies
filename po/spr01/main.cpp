#include <iostream>

/*
 * funkcje przeładowane,
 * pojedynczy wskaźnik na strukturę,
 * tablica obiektów struktur (dynamiczna)
 * tablica dynamiczna wskaźników struktury
 */
using namespace std;

struct A
{
    int i;
};

void A_create(A*&);
void A_create(A*&, int);
void A_create(A**&, int);
void A_set(A*, int);
void A_set(A*, int, int);
void A_set(A**, int, int);
void A_del(A*);
void A_del(A*, int);
void A_del(A**, int);
void A_print(A*);
void A_print(A*, int);
void A_print(A**, int);

int main()
{
    //-------------------------------------
    cout << "Pojedynczy wskaźnik:" << endl;
    A* a;
    A_create(a);
    A_set(a, 10);
    A_print(a);
    A_del(a);

    //-------------------------------------
    cout << "\nDynamiczna tablica:" << endl;
    int el = 10;

    A* b;
    A_create(b, el);
    for(int i=0; i<el; ++i){
    	A_set(b, i, i);
    }
    A_print(b, el);
    A_del(b, el);

    //-------------------------------------
    cout << "\nTablica wskaźnków:" << endl;
    el = 7;

    A** c;
    A_create(c, el);
    for(int i=0; i<el; ++i){
	A_set(c, i, el*i);
    }
    A_print(c, el);
    A_del(c, el);

    return 0;
}

// Pojedynczy wskaźnik
void A_create(A*& a)
{
    a = new A;
}

void A_set(A* a, int v)
{
    a->i = v;
}

void A_del(A* a)
{
    delete a;
}

void A_print(A* a)
{
    cout << a->i << endl;
}

// Dynamiczna tablica
void A_create(A*& a, int v)
{
    a = new A[v];
}

void A_set(A* a, int i, int v)
{
    a[i].i = v;
}

void A_del(A* a, int i)
{
    delete[] a;
}

void A_print(A* a, int n)
{
    for(int i=0; i<n; ++i){
	cout << a[i].i << endl;
    }
}

// Tablica wskaźników
void A_create(A**& a, int n)
{
    a = new A*[n];

    for(int i=0; i<n; ++i){
	a[i] = new A;
    }
}

void A_set(A** a, int i, int v)
{
    A_set(a[i], v);
}

void A_del(A** a, int n)
{
    for(int i=0; i<n; ++i){
	delete a[i];
    }
    delete a;
}

void A_print(A** a, int n)
{
    for(int i=0; i<n; ++i){
	A_print(a[i]);
    }
}
