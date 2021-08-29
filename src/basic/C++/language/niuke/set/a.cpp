#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    //成员函数重载 ==运算符
    bool operator==(const Person &ob)
    {
        if (this->name == ob.name && this->age == ob.age)
            return true;
        return false;
    }

    bool operator<(const Person &ob)
    {
        if (this->age < ob.age)
            return true;
        return false;
    }
};
void printListPerson(list<Person> &L)
{
    cout << "‐‐‐‐‐‐‐‐‐‐‐" << endl;
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << (*it).name << " " << (*it).age << endl;
    }
}
void test01()
{
    //存放自定义数据
    list<Person> L;
    L.push_back(Person("德玛西亚", 48));
    L.push_back(Person("提莫", 28));
    L.push_back(Person("狗头", 18));
    L.push_back(Person("牛头", 19));

    printListPerson(L);

    //删除狗头
    Person tmp("狗头", 18);
    //重载==运算符
    L.remove(tmp);
    printListPerson(L);
}

void test02()
{
    //存放自定义数据
    list<Person> L;
    L.push_back(Person("德玛西亚", 48));
    L.push_back(Person("提莫", 28));
    L.push_back(Person("狗头", 18));
    L.push_back(Person("牛头", 19));
    printListPerson(L);

    //对于自定义数据 我们可以重载<运算符
    L.sort();

    printListPerson(L);
}
int main(int argc, char *argv[])
{
    //test01();
    test02();
    return 0;
}
