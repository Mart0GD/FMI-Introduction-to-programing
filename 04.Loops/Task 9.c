#include<stdio.h>

/*
Напишете програма, която прочита цяло положително число n и извежда n-тото число на Фибоначи
Запознайте се с числата на Фибоначи: Wikipedia
*/
int main9()
{
	int n;
	scanf_s("%d",  &n);

	if (n == 0) 
	{ 
		puts("0"); 
		return 0;
	}
	else if (n == 1) 
	{ 
		puts("1"); 
		return 0;
	}
	else if (n == 2) 
	{ 
		puts("1"); 
		return 0;
	}

	int prePredecessor = 1;
	int predecessor = 1;
	int number = 0;
	for (int i = 3; i <= n; i++)
	{
		number = predecessor + prePredecessor;

		prePredecessor = predecessor;
		predecessor = number;
	}

	printf("%d", number);
	return 0;
}