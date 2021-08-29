#include <bits/stdc++.h>

using namespace std;

//指针交换法（前后指针）--->递归
void quickSort(int *array, int left, int right)
{
    if (left >= right)
        return;
    int Index = partsort(array, left, right);
    //分开而治
    //左半部分
    quickSort(array, left, Index - 1);
    //右半部分
    quickSort(array, Index + 1, right);
}

void QuickSort(int *array, int left, int right)
{

    stack<int> s;

    s.push(left);

    s.push(right);

    while (!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        //划分左右部分的边界线
        int Index = partsort(array, left, right);

        //左半部分
        if (Index - 1 > left)
        {
            s.push(left);
            s.push(Index - 1);
        }

        //右半部分
        if (Index + 1 < right)
        {
            s.push(Index + 1);
            s.push(right);
        }
    }
}

int partsort(int *array, int left, int right)
{

    int Index = left;
    int ponit = array[Index];

    while (left < right)
    {
        while (left < right && array[right] >= ponit)
            --right;
        while (left < right && array[left] <= ponit)
            ++left;

        int temp = array[right];
        array[right] = array[left];
        array[left] = temp;
    }

    int num = array[left];
    array[left] = array[Index];
    array[Index] = num;
    return left;
}
int main()
{

    return 0;
}