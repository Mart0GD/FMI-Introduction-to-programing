#include<stdio.h>

int main11() 
{
	int n;
	scanf_s("%d", &n);

	puts("{ }");
	if (n == 0) { return; }

	int combinations = 0;
	int combinationsTemp;;
	for (int i = 1; i <= n; i++)
	{
		combinationsTemp = 1;
		printf("{ %d }\n", i);
		for (int j = 1; j < i; j++)
		{
			printf("{ %d %d }\n", j, i);
			combinationsTemp++;
		}


		combinations+= combinationsTemp;
	}

	return 0;
}