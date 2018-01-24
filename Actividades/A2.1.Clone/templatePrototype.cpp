#include<iostream>
using namespace std;

class Moviles
{
    int t;
public:
    Moviles(int t) : t(t){}
    virtual Moviles* clone() = 0;
};

template<class Base, class Subclass>
class CloneCRTP : public Base
{
public:
    Base* clone()
    {
        return new Subclass(dynamic_cast<Subclass&>(*this));
    }
};

class Tablet : public CloneCRTP<Moviles, Tablet>, public Base
{
public:
    Tablet() = default;
    Tablet(int t) : Moviles(t){}
    void doTabletOperations(){}
};

int main()
{
    Moviles* m = new Tablet;
    //dynamic_cast<Table&>(m)->doTabletOperations();
}