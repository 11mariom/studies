#include <iostream>

using namespace std;

class A
{
    int i;

public:
    A();
    A(int);
    void print();
    void set(int);
    int get() const;
    int& badget();
};

int main()
{
    // pierwszy konstruktor
    A a;
    a.print();
    a.set(10);
    a.print();

    int i = a.get();
    cout << i << endl;

    // ojej, nadpisze
    a.badget() = 999;
    a.print();

    // drugi konstruktor
    A b(100);
    b.print();
    
    // wskaźnik
    A* c;
    c = new A(199);
    c->print();
    delete c;

    // tablica wskaźników
    A** d;
    d = new A*[5];
    
    for(int i=0; i<5; ++i){
	d[i] = new A(i);
	d[i]->print();
    }

    for(int i=0; i<5; ++i){
	delete d[i];
    }
    delete d;
    
    return 0;
}

A::A()
{
    i = 777;
}

A::A(int j)
{
    i = j;
}

void A::print() 
{
    cout << i << endl;
}

void A::set(int j)
{
    i = j;
}

int A::get() const
{
    return i;
}
   
//ojoj :D dodaj ↓ const to wypluje błąd
int& A::badget()
{
    return i;
}
