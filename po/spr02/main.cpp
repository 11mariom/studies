#include <iostream>

using namespace std;


//-------------
class A 
{
    int i_;
public:
    A(){};
    A(int);
    void set(int);
    int get();
    void print();
};

void create(A*&, int);
void create(A**&, int);
void erase(A*, int);
void erase(A**, int);
void add(A*&, int&, int);
void add(A**&, int&, int);
void del(A*&, int&, int);
void del(A**&, int&, int);
void print(A*, int);
void print(A**, int);

int main()
{
    std::cout << "- Tablica obiektów" << std::endl;
    A* a;
    int size_a = 4;

    create(a, size_a);

    for(int i = 0; i < size_a; ++i)
	a[i].set(i);
    print(a, size_a);

    std::cout << "-- dodanie obiektu" << std::endl;
    add(a, size_a, 100);
    print(a, size_a);

    int index = 2;
    std::cout << "-- usunięcie obiektu; index = " << index << std::endl;
    del(a, size_a, index);
    print(a, size_a);

    erase(a, size_a);

    std::cout << "- Tablica wksaźków" << std::endl;
    A** b;
    int size_b = 7;
    
    create(b, size_b);

    for(int i = 0; i < size_b; ++i)
	b[i]->set( i*2 );
    print(b, size_b);

    std::cout << "-- dodanie obiektu" << std::endl;
    add(b, size_b, 128);
    print(b, size_b);

    index = 3;
    std::cout << "-- usunięcie obiektu; index = " << index << std::endl;
    del(b, size_b, index);
    print(b, size_b);

    erase(b, size_b);


    return 0;
}

A::A(int i)
{
    i_ = i;
}

void A::set(int i)
{
    i_ = i;
}

int A::get()
{
    return i_;
}

void A::print()
{
    std::cout << i_ << std::endl;
}

void create(A*& a, int size)
{
    a = new A[size];
}

void create(A**& a, int size)
{
    a = new A*[size];
    
    for(int i = 0; i < size; ++i)
	a[i] = new A;
}

void erase(A* a, int size)
{
    delete[] a;
}

void erase(A** a, int size)
{
    for(int i = 0; i < size; ++i)
	delete a[i];
    delete a;
}

void add(A*& a, int& size, int v)
{
    A* tmp;
    create(tmp, size+1);

    for(int i = 0; i < size; ++i)
	tmp[i].set( a[i].get() );
    tmp[size].set(v);
    a = tmp;

    ++size;
}

void add(A**& a, int& size, int v)
{
    A** tmp;
    create(tmp, size+1);

    for(int i = 0; i < size; ++i)
	tmp[i]->set( a[i]->get() );
    tmp[size]->set(v);
    a = tmp;
    
    ++size;
}

void del(A*& a, int& size, int index)
{
    A* tmp;
    create(tmp, size-1);
    
    for(int i = 0; i < index; ++i)
	tmp[i].set( a[i].get() );
    for(int i = index + 1; i < size; ++i)
	tmp[i-1].set( a[i].get() );
    a = tmp;

    --size;
}

void del(A**& a, int& size, int index)
{
    A** tmp;
    create(tmp, size-1);

    for(int i = 0; i < index; ++i)
	tmp[i]->set( a[i]->get() );
    for(int i = index + 1; i < size; ++i)
	tmp[i-1]->set( a[i]->get() );
    a = tmp;

    --size;
}

void print(A* a, int size)
{
    for(int i = 0; i < size; ++i)
	a[i].print();
}

void print(A** a, int size)
{
    for(int i = 0; i < size; ++i)
	a[i]->print();
}

