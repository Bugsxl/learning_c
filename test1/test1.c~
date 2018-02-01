#include "stdio.h"

#define CAL 5
#define N 12

void stdline(int *h, int n)
{
	int i;
	for (i = 1; i <= n; i++)
		*(h + i - 1) = i;
}
void outline(int *h, int n, int call)
{
	int *p, total, callnum;
	total = 0;
	callnum = 0;
	p = h;
	while (total < n)
	{
		if (*p != 0)
			callnum++;
		if (callnum == call)
		{
			printf("%d ", *p);
			total++;
			if (total == n)
			{
				*h = *p;
				return;
			}
			callnum = 0;
			*p = 0;
		}
		p++;
		if (p > h + n - 1)
		{
			p = h;
		}
	}
}
void main()
{
	int a[N];
	stdline(a, N);
	outline(a, N, CAL);
	printf("最后留下来的是%d号\n", *a);
}
