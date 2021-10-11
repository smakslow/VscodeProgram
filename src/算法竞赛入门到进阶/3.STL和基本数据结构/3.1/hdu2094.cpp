#include <iostream>
#include <set>
#include <string>

using namespace std;
/*
 set<Type> s;
 s.insert(item)
 s.erase(item)
 s.clear()
 s.empry()
 s.size()
 s.find(k)   返回一个迭代器，指向键值k
 s.lower_bound(k)  返回一个迭代器，指向键值不小于k的第一个元素
 s.upper_bound(k)  返回一个迭代器，指向键值大于k的第一个元素
*/
int main()
{
    set<string> All, Fail;
    string s1, s2;
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            All.insert(s1);
            All.insert(s2);
            Fail.insert(s2);
        }
        if (All.size() - Fail.size() == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        All.clear();
        Fail.clear();
    }
    return 0;
}
