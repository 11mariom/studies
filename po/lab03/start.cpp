#include <iostream>

using namespace std;

struct A
{
public:
    int i;
};

struct B
{
private:
    int i;
};

class C
{
    int i;
};


int main()
{
    A a;
    a.i = 10;

    /* nie zadziała, bo i jest prywatne
     * B b;
     * b.i = 10;
     */

    /* nie zadziała, bo i jest prywatne
     * C c;
     * c.i = 10;
     */


    
    return 0;
}

