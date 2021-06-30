#include <iostream>

using namespace std;

namespace longnamespace
{
    int a = 20;
    int b = 30;

    void say()
    {
        cout << "a " << a << " "
             << "b " << b << endl;
    }
}

int main()
{
    int a = 100;
    namespace name = longnamespace;
    using namespace name;
    cout << a << endl;
    cout << name ::a << endl;
    cout << b << endl;
    name ::say();
    return 0;
}