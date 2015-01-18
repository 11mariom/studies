#include <iostream>

class A
{
    int a_;
public:
    A(int a = 0) : a_(a) {}
    virtual void print();
    int geta();
};

class B : virtual public A
{
    int b_;
public:
    B(int b = 0) : A(b + 1), b_(b) {}
    virtual void print();
    int getb();
};

class C : virtual public A
{
    int c_;
public:
    C(int c = 0) : A(c + 1), c_(c) {}
    virtual void print();
    int getc();
};

class D : virtual public B, virtual public C
{
    int d_;
public:
    D(int d = 0) : A(d + 3), B(d + 2), C(d + 1), d_(d) {};
    virtual void print();
    int getd();
};

class Store
{
    A** a_;
    int max_;
    int size_;
public:
    Store(int max = 0) : a_(new A*[max]), max_(max), size_(0) {};
    ~Store();
    void add(A* a);
    void print();
};

int main()
{
    Store s(1);

    s.add(new A(1));
    s.add(new C(3));
    s.add(new D(3));
    s.print();

    for(int i = 0; i < 8; ++i){
	s.add(new C(i+3));
    }
    s.print();

    return 0;
}

void Store::add(A* a)
{
    if(size_ == max_){
	A** tmp = new A*[size_ + max_];
	for(int i = 0; i < size_; ++i)
	    tmp[i] = a_[i];
	tmp[size_] = a;
	a_ = tmp;
	max_ = size_ + max_;
    } else {
	a_[size_] = a;
    }

    ++size_;
}

void Store::print()
{
    for(int i = 0; i < size_; ++i){
	std::cout << "Store " << i << ": ";
	a_[i]->print();
    }
}

void A::print()
{
    std::cout << "Class A: " << a_ << std::endl;
}

int A::geta()
{
    return a_;
}

void B::print()
{
    std::cout << "Class B: b = " << b_ << std::endl;
}

int B::getb()
{
    return b_;
}

void C::print()
{
    std::cout << "Class C: c = " << c_ << " a = " << geta() << std::endl;
}

void D::print()
{
    std::cout << "Class D: d = " << d_ << " b = " << getb()
	      << " a = " << geta() << std::endl;
}


Store::~Store()
{
    delete[] a_;
}

