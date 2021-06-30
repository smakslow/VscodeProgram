#include <iostream>
#include <cstring>

using namespace std;
void test01()
{
    //string(const char* s);//使用字符串s初始�?
    string str1("hello string");
    cout << str1 << endl; //"hello string"

    //string(int n, char c);//使用n个字符c初始�?
    string str2(10, 'H');
    cout << str2 << endl; //"HHHHHHHHHH"27
    string str3 = str2;
    cout << str3 << endl; //"HHHHHHHHHH"

    string str4;
    //string& operator=(const string &s);//把字符串s赋给当前的字符串
    str4 = str1;
    cout << str4 << endl; //"hello string"

    //string& operator=(const char* s);//char*类型字符�? 赋值给当前的字符串
    string str5;
    str5 = "hello str5";
    cout << str5 << endl; //"hello str5"

    //string& operator=(char c);//字符赋值给当前的字符串
    string str6;
    str6 = 'H';
    cout << str6 << endl; //"H"

    //string& assign(const char *s);//把字符串s赋给当前的字符串
    string str7;
    str7.assign("hello str7");
    cout << str7 << endl; //"hello str7"

    //string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符�?
    string str8;
    str8.assign("hello str8", 5);
    cout << str8 << endl; //"hello"

    //string& assign(const string &s);//把字符串s赋给当前字符�?
    string str9;
    str9.assign(str8);
    cout << str9 << endl; //"hello"

    //string& assign(int n, char c);//用n个字符c赋给当前字符�?
    string str10;
    str10.assign(10, 'W');
    cout << str10 << endl; //"WWWWWWWWWW"

    //string& assign(const string &s, int start, int n);//将s从start开始n�?
    string str11;
    str11.assign("hehehahahaxixi", 4, 6);
    cout << str11 << endl; //"hahaha"
}

void test02()
{
    string str1 = "hello string";
    cout << str1[1] << endl;    //'e'
    cout << str1.at(1) << endl; //'e'

    str1[1] = 'E';
    cout << str1 << endl; //"hEllo string"
    str1.at(7) = 'T';
    cout << str1 << endl; //"hEllo sTring"

    //[]和at的区�?
    try
    {
        //str1[1000]='G';//越界 []不抛出异�?
        str1.at(1000) = 'G'; //越界 at会抛出异�?
    }
    catch (exception &e)
    {
        cout << "异常:" << e.what() << endl;
    }
}
void test03()
{
    string str1 = "hello";
    string str2 = " string";
    //string& operator+=(const string& str);//重载+=操作�?
    str1 += str2;
    cout << str1 << endl; //"hello string"

    string str3 = "hello";
    //string& operator+=(const char* str);//重载+=操作�?
    str3 += " string";
    cout << str3 << endl; //"hello string"

    string str4 = "hello";
    //string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结�?
    str4.append("hehehaha", 4);
    cout << str4 << endl; //"hellohehe"

    //string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结�?
    string str5 = "hello";
    string str6 = "hehehahaha";
    str5.append(str6, 4, 6);
    cout << str6 << endl; //"hellohahaha"
}

void test04()
{
    //int find(const string& str, int pos = 0) const; //查找str第一次出现位�?,从pos开始查�?
    string str1 = "hehe:haha:xixi:haha:heihei";
    //从str1中找haha
    string tmp = "haha";
    cout << str1.find(tmp) << endl;     //5
    cout << str1.find(tmp, 10) << endl; //15

    //int find(const char* s, int pos = 0) const; //查找s第一次出现位�?,从pos开始查�?
    cout << str1.find("haha") << endl; //527
    str1.replace(5, 4, "###");
    cout << str1 << endl; //"hehe:###:xixi:haha:heihei"

    string str2 = "www.sex.117114.sex.person.77.com";
    //需求：将字符串中的所�?"sex"�?***屏蔽
    int ret = 0;
    while ((ret = str2.find("sex")) < str2.size())
    {
        str2.replace(ret, strlen("sex"), "***");
    }
    cout << str2 << endl;
}

/* string比较操作
 compare函数�?>时返�? 1�?<时返�? �?1�?==时返�? 0�?
 比较区分大小写，比较时参考字典顺序，排越前面的越小�?
 大写的A比小写的a小�?
 int compare(const string &s) const;//与字符串s比较
 int compare(const char *s) const;//与字符串s比较
 */

void test05()
{
    string str1 = "hehe";
    string str2 = "haha";
    cout << str1.compare(str2) << endl;   //1
    cout << str1.compare("lala") << endl; //�?1
    cout << str1.compare("hehe") << endl; //0
}
int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}