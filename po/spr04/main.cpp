#include <iostream>

class B
{
    int i_;
public:
    B(int i=0){
	i_ = i;
    }
    void set(int i){
	i_ = i;
    }
    int get(){
	return i_;
    }
    void print(){
	std::cout << i_ << std::endl;
    }
};

class A
{
    B* b_;
    int i_;
public:
    A(int s=0){
	i_ = s;
	b_ = new B[s];
	for(int i = 0; i < s; ++i)
	    b_[i].set(i);
    }
    ~A(){
	delete[] b_;
    }
    void print(){
	std::cout << i_ << ":";
	for(int i = 0; i < i_; ++i)
	    std::cout << " " << b_[i].get();
	std::cout << std::endl;
    }
    B& operator[] (int);
    int operator() ();
    A* operator-> ();
    A& operator= (A&);
    friend std::ostream& operator<< (std::ostream&, const A&);
    friend std::istream& operator>> (std::istream&, A&);
    A& operator++ ();
    A operator++ (int);
    bool operator== (A&);
    bool operator!= (A&);
};

int main()
{
    A a(10), b(5);

    std::cout << "cout << a: " << a << std::endl
	      << "a(): " << a() << std::endl << std::endl;

    a = b;
    std::cout << "a = b: " << a << std::endl
	      << "a[3].print(): ";

    a[3].print();

    //std::cout << "New a size: ";
    //std::cin >> a;
    //a.print();

    std::cout << "\na++: " << a++ << "after: " << a;
    std::cout << "++a: " << ++a << std::endl;

    A c(5), d(5);
    std::cout << "a: " << a << "b: " << b << "c: " << c << "d: " << d;

    if(a == b){
	std::cout << "a == b: prawda\n";
    } else {
	std::cout << "a == b: fałsz\n";
    }
    if(a != b){
	std::cout << "a != b: prawda\n";
    } else {
	std::cout << "a != b: fałsz\n";
    }

    if(c == d){
	std::cout << "c == d: prawda\n";
    } else {
	std::cout << "c == d: fałsz\n";
    }
    if(c != d){
	std::cout << "c != d: prawda\n";
    } else {
	std::cout << "c != d: fałsz\n";
    }

    return 0;
}

B& A::operator[] (int i)
{
    return b_[i];
}

int A::operator() ()
{
    int res = 0;
    for(int i = 0; i < i_; ++i)
	res += b_[i].get();
    return res;
}

A* A::operator-> ()
{
    return this;
}

A& A::operator= (A& src)
{
    delete[] b_;

    i_ = src.i_;
    b_ = new B[i_];
    for(int i = 0; i < i_; ++i)
	b_[i].set(src.b_[i].get());
}

std::ostream& operator<< (std::ostream& str, const A& a)
{
    str << a.i_ << ":";
    for(int i = 0; i < a.i_; ++i)
	str << " " << a.b_[i].get();
    return str << std::endl;
}

std::istream& operator>> (std::istream& str, A& a)
{
    int i;
    str >> i;

    A* b = new A(i);
    a = *b;
}

A& A::operator++ ()
{
    for(int i = 0; i < i_; ++i)
	b_[i].set(b_[i].get() + 1);
    return *this;
}

A A::operator++ (int)
{
    A tmp(this->i_);
    ++(*this);
    return tmp;
}

bool A::operator== (A& src)
{
    if( i_ == src.i_ ){
	for(int i = 0; i < i_; ++i)
	    if(b_[i].get() != src.b_[i].get())
		return false;
	return true;
    }
    return false;
}

bool A::operator!= (A& src)
{
    if( i_ == src.i_ ){
	for(int i = 0; i < i_; ++i)
	    if(b_[i].get() != src.b_[i].get())
		return true;
	return false;
    }
    return true;
}
