#include<stdio.h>

int main_03_12()
{
	int rows = 0;
	scanf_s("%d", &rows);

	int sizeOfLastRow = 3 + (2 * (rows - 1));

	for (int i = 0; i < rows; i++)
	{
		for (int z = 0; z < i; z++)
		{
			printf(" ");
		}
		for (int j = 0; j < sizeOfLastRow - (2 * i); j++)
		{
			printf("*");
		}
		puts("");
	}


	for (int i = rows; i >= 0; i--)
	{
		for (int z = 0; z < i; z++)
		{
			printf(" ");
		}
		for (int j = 0; j < sizeOfLastRow - (2 * i); j++)
		{
			printf("*");
		}
		puts("");
	}

	return 0;
}