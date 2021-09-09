#include<iostream>
using namespace std;
class Base
{
public:
    virtual void foo(){cout << 'a';}   
};
class Middle:public Base
{
public:
    void foo(){cout <<'b';}
};
class Derived:public Middle
{
public:
    void foo(){cout <<'c';}
};
int main()
{
    Base* p1;
    Middle* p2;
    Derived d;
    p1 = &d;
    p1->foo();
    p2 = &d;
    p2->foo();
}