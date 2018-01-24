#include<stdlib.h>
#include<iostream>

using namespace std;

template<int N>
class SomeClass
{
};

template<int N>
struct tricky
{
    int sq()
    {
        return N*N;
    }
};

/*template parameters can depend on previous parameters*/
template<
    class T,
    int (*func)(T)       /*pointer to a function reveiving T and returning int*/
    >
class otherClass
{

};

int func(int n)
{
    return n;
}

int main()
{
    int N = rand();
    const int y = 2;
    //SomeClass<N> v;     //eror N is not a compile time constant
    SomeClass<y> w;         //compiles correctly because w is a compile-time constant
    SomeClass<5+5%2> z;
    tricky<5> i;
    cout << i.sq();
    
}