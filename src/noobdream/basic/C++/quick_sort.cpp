#include <stdio.h>

 const int maxn = 100005;
        int a[maxn];
        //快速排序
    void Quick_Sort(int l, int r) {
        if(l >= r) return;
        int i = l,j = r,x = a[l];
        while (i < j) {
        while (i < j && a[j] >= x) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] < x) i++;
        if (i < j) a[j--] = a[i];
        }
        a[i] = x;
        Quick_Sort(l, i - 1);
        Quick_Sort(i + 1, r);
   }
     int main() {
        int n;
        scanf("%d", &n);
        Quick_Sort(1, n);//传入左边界下标和右边界下标
        for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
 }