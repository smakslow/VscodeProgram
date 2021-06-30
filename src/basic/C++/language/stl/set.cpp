#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << endl;
    }

    set<string> country;     //定义一个存放 string 的集合
    country.insert("China"); //插入操作
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    //使用迭代器遍历集合元素
    for (it = country.begin(); it != country.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    country.erase("American"); //删除集合内的元素
    country.erase("England");
    if (country.count("China"))
    {
        cout << "China in country." << endl;
    }
    country.clear(); //清空集合

    return 0;
}