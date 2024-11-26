#include<stdio.h>
#include<math.h>
/*
Задача 15: Напишете програма, която приема две естествени числа n и k и пресмята стойността на log_k(n), закръглена надолу.
Вход: 16 2, Изход: 4
Вход: 100000 2, Изход: 16
Вход: 35 3, Изход: 3
Вход: 256 16, Изход: 2
*/
int main_03_15()
{
	int  base, product;
	scanf_s("%d %d", &product , &base);

	int power = 0;
	int newNumber = 1;
	while (newNumber <= product)
	{
		power++;  
		newNumber *= base;
	}

	printf("%d", power - 1);
	return 0;
}