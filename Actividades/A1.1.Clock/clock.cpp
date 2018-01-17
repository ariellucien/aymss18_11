#include<iostream>
using namespace std;

class Other{};
class Clock
{
private:
    static Clock* instance;
    Clock() 
    {
        cout <<"constructor";
    }
public:
    static Clock* getInstance()
    {
        if (instance == 0)
        {
            instance = new Clock;
        }
        return instance;
    }
    void getTime()
    {
        cout << "son las 8:55" << endl;
    } 

};
Clock* Clock::instance = 0;

template<class T>
void doSome()
{
    T* a;
    a->getTime();
}

int main()
{
    doSome<Clock>();
    Clock* instance1 = Clock::getInstance();
    instance1->getTime();
    Clock* instance2 = Clock::getInstance();
    instance2->getTime();
    cout << instance1 << endl;
    cout << instance2 << endl;

    //delete instance1;
    //delete instance2;

}