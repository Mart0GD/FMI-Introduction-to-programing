#include<stdio.h>

int main_03_13()
{
	int rows = 0;
	scanf_s("%d", &rows);

	int lastRowSize = 3 + (2 * (rows - 1));


	for (int i = rows; i >= 0; i--)
	{
		for (int z = 0; z < i; z++)
		{
			printf(" ");
		}
		for (int j = 0; j < lastRowSize - (2 * i); j++)
		{
			printf("*");
		}
		puts("");
		puts("");
	}

	for (int i = 0; i < rows / 2; i++)
	{
		for (int i = 0; i < lastRowSize / 2; i++)
		{
			printf(" ");
		}
		puts("*");
		puts("");
	}
	
	return 0;
}