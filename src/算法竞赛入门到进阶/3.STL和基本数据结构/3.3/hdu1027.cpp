#include <iostream>
#include <algorithm>

using namespace std;

/*
  bool next_permutation(BidirectionalIterator first,BidirectionalIterator first)
  bool next_permutation(BidirectionalIterator first,BidirectionalIterator first,Compare comp)
  如果没有下一个排列组合，返回false,否则返回true

  相关函数：
        prev_permutation()  求前一个排列组合
        lexicographical_compare()   字典比较
*/
int a[1001];
int main()
{
  int n, m;
  while (cin >> n >> m)
  {
    for (int i = 1; i <= n; i++)
    {
      a[i] = i;
    }
    int b = 1;
    do
    {
      if (b == m)
        break;
      b++;
    } while (next_permutation(a + 1, a + n + 1));
    for (int i = 1; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << a[n] << endl;
  }
  return 0;
}