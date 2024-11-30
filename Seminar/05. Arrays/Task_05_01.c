#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
Задача 1: Напишете функция, която приема масив и елемент и връща индекса на първото срещане на елемента в масива, ако има такова, и -1, в противен случай.
Вход: 17 23 5 -14 0    -14, Изход: 3
Вход: 17 23 5 8 0       -14, Изход: -1
*/

int firstOrDefaultIndex(const int arr[], const int numberTofind, const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == numberTofind)
		{
			return i;
		}
	}

	return -1;
}

int fillArray_2(int arr[], const int arrLength) {

	puts("Insert values!");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int main_05_01()
{
	int arr[MAX_ARR_LENGTH];
	int arrLength = 0;

	puts("Insert array size (max 128)");
	scanf_s("%d", &arrLength);
	fillArray_2(arr, arrLength);

	short n = 0;
	puts("Insert number to find!");
	scanf_s("%hu", &n);

	int indexOfN = firstOrDefaultIndex(arr, n, arrLength);
	printf("Index -> %d", indexOfN);
	return 0;
}