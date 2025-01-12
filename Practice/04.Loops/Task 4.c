#include<stdio.h>

int main_4()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 2; i <= n; i+=2)
	{
		printf("%d\n", i);
	}
}