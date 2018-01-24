#include<iostream>
using namespace std;

class Product
{
public:    
    virtual void operacion1() = 0;
    virtual void operacion2() = 0;
};

class Producto1 : public Product
{
public:
  void operacion1()
  {
      cout << "Estoy en operacion 1 Prod 1";
  }
  void operacion2()
  {
      cout << "Estoy en operacion 2 Prod 1";
  }
  void describeMe()
  {
      cout << "soy un producto terminado";
  }
};

class Creator
{
    template<class Tipo>
    Tipo* factoryMethod()
    {
        return new Tipo;
    }
public:
    template<class Tipo>
    Tipo* create()
    {
        Tipo* temporal;
        temporal = factoryMethod<Tipo>();
        temporal->operacion1();
        temporal->operacion1();
        return temporal;
    }
};
int main()
{
    Creator* c = new Creator;
    Producto1* p1 = c->create<Producto1>();
    p1->describeMe();

    return 0;
}