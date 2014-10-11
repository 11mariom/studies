#include <iostream>

// deklaracje struktur
struct A;

// deklaracje funkcji
void create(A*&);
void erase(A*);
void set(A*, int);
void print(A*);

// tabela
void create(A*&, int);
void erase(A*, int);
void set(A*, int, int);
void print(A*, int);

int main()
{
    A *a;
    
    create(a);
    set(a, 7);
    print(a);
    erase(a);

    A *b;
    create(b, 5);
    set(b, 5, 10);
    print(b, 5);
    erase(b, 5);

    return 0;
}

// definicje struktur
struct A
{
    int i;
};

// definicje funkcji
void create(A*& a)
{
    a = new A;
}

void erase(A* a)
{
    delete a;
}

void set(A* a, int value)
{
    a->i = value;
}

void print(A* a)
{
    std::cout << a->i << std::endl;
}

// tabela
void create(A*& a, int size)
{
    a = new A[size];
}

void erase(A* a, int size)
{
    delete[] a;
}

void set(A* a, int value, int size)
{
    for(int i=0; i < size; ++i)
	set(&a[i], value);
}

void print(A* a, int size)
{
    for(int i=0; i < size; ++i)
	print(&a[size]);
}
