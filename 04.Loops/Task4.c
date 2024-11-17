#include<stdio.h>

int main4()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 2; i <= n; i+=2)
	{
		printf("%d\n", i);
	}
}