#include <iostream>

class A
{
    class B
    {
	int i_;
    public:
	B();
	B(int);
	int get();
	void set(int);
    };
    B **b;
    int size_;
public:
    A();
    A(int, int);
    A(const A*);
    ~A();
    int sum();
    void print();
};

void create(A**&, int);
void copy(A**, A**&, int);
void print(A**, int);
void erase(A**, int);

int main()
{
    A **a;
    int size = 10;

    create(a, size);
    print(a, size);

    for(int i = 0; i < size; ++i)
	std::cout << " " << a[i]->sum();
    std::cout << std::endl;

    A **b;

    copy(a, b, size);
    print(b, size);

    for(int i = 0; i < size; ++i)
	std::cout << " " << b[i]->sum();
    std::cout << std::endl;

    erase(a, size);
    erase(b, size);

    return 0;
}

A::B::B(int i)
{
    i_ = i;
}

void A::B::set(int i)
{
    i_ = i;
}

int A::B::get()
{
    return i_;
}

A::A(int i_, int size)
{
    size_ = size;
    b = new B*[size];

    for(int i = 0; i < size_; ++i)
	b[i] = new B(i_);
}

A::A(const A* src)
{
    size_ = src->size_;
    b = new B*[size_];

    for(int i = 0; i < size_; ++i)
	b[i] = new B(src->b[i]->get());
}

A::~A()
{
    for(int i = 0; i < size_; ++i)
	delete b[i];
    delete[] b;
}

int A::sum()
{
    int res = 0;

    for(int i = 0; i < size_; ++i)
	res += b[i]->get();

    return res;
}

void A::print()
{
    //std::cout << b << std::endl;
    for(int i = 0; i < size_; ++i)
	std::cout << " " << b[i]->get();
    std::cout << std::endl;
}

void create(A**& a, int size)
{
    a = new A*[size];

    for(int i = 0; i < size; ++i)
	a[i] = new A(i, size);
}

void copy(A** src, A**& a, int size)
{
    a = new A*[size];

    for(int i = 0; i < size; ++i)
	a[i] = new A(src[i]);
}

void print(A** a, int size)
{
    for(int i = 0; i < size; ++i)
	a[i]->print();
}

void erase(A** a, int size)
{
    for(int i = 0; i < size; ++i)
	delete a[i];
    delete[] a;
}
