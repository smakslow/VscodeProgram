#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myPrintInt(int val);
void test01()
{
    //单端动态数组vector 类模板
    vector<int> v; //v就是一个具体的vector容器

    //pash_back 尾部插入
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);

    //访问数据
    //定义一个迭代器存储 v的起始迭代器
    vector<int>::iterator biginIt = v.begin();
    //定义一个迭代器存储 v的结束迭代器
    vector<int>::iterator endIt = v.end();

    //for循环遍历1
    for (; biginIt != endIt; biginIt++)
    {
        //对迭代器取* 代表的是 容器的元素
        //*biginIt
        cout << *biginIt << " ";
    }
    cout << endl;

    //for循环遍历2（推荐）
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //STL提供的算法来遍历容器(包含算法头文件 algorithm)
    //for_each 从容器的起始‐‐‐>结束 逐个元素取出
    //myPrintInt 容器数据的打印方式
    for_each(v.begin(), v.end(), myPrintInt);
    cout << endl;
}

void myPrintInt(int val)
{
    cout << val << " ";
}

//================================================================
class Person{
    string name;
    int age;
};
void myPrintPerson(Person &ob)
{
    cout << "name = " << ob.name << ", age =" << ob.age << endl;
}
void test02()
{
    Person ob1("德玛", 18);
    Person ob2("小炮", 28);
    Person ob3("小法", 38);
    Person ob4("小智", 48);

    //定义一个vector容器存放ob1~ob4的数据
    vector<Person> v;
    v.push_back(ob1);
    v.push_back(ob2);
    v.push_back(ob3);
    v.push_back(ob4);

    for_each(v.begin(), v.end(), myPrintPerson);
}
int main(int argc, char *argv[])
{
    //test01();
    test02();
    return 0;
}