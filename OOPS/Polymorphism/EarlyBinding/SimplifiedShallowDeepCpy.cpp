#include <iostream>
using namespace std;

class Shallow
{
    int* data;
    
    public:
    Shallow(int v)
    { 
        data = new int(v);
    }
    ~Shallow() 
    { 
        delete data; 
    }
};

class Deep 
{
    int* data;
    public:
    Deep(int v) 
    {
       data = new int(v); 
    }
    Deep(const Deep& d) 
    {
       data = new int(*d.data); 
    }
    ~Deep()
     { 
        delete data; 
     }
};

int main()
{
    Shallow a(1);
    Shallow b = a; //  Shallow copy (unsafe)

    Deep x(2);
    Deep y = x;    // Deep copy (safe)
}
/* Expected Output
double free Error
Aborted (core dumped)



*/
