#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <string>
using namespace std;
int a[30001],pre[30001];
int find(int x)
{
    if(pre[x]==x)
    return x;
    else
   return pre[x]=find(pre[x]);
}
void mix(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
		pre[fy] = fx;
}
int main()
{
	//freopen("C:\\in.txt","r",stdin);
	int n,m;
	while (scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
			pre[i] = i;
		for (int i = 0; i < m; i++)
		{
			int k;
			scanf("%d", &k);
			if (k >= 1)
			{
				scanf("%d", &a[0]);
				for (int j = 1; j < k; j++)
				{
					scanf("%d", &a[j]);
					mix(a[0], a[j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
			if (find(i) ==pre[0])
				sum++;
		printf("%d\n", sum);
	}
	return 0;
}