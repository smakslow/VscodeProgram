#include <iostream>
#include <algorithm>
using namespace std;
int a[101], n;

void quickSort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;

    temp = a[left];
    i = left;
    j = right;
    while (i < j)
    {
        while (i < j && a[j] >= temp)
            j--;
        while (i < j && a[i] <= temp)
            i++;

        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = temp;

    quickSort(left, i - 1);
    quickSort(i + 1, right);
    return;
}

int main()
{
    int i, j;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quickSort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    getchar();
    getchar();
    return 0;
}