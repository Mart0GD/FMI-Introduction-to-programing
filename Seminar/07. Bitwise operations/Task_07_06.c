#include<stdio.h>
#define ARR_LENGTH 128
/*
Задача 6: Напишете функция, която приема масив (разглеждаме го като множество) и отпечатва всички негови подмножества.
Вход: [1, 2, 3], Изход: [], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]
*/

void fillArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		arr[i] = i + 1;
		printf("Element %d. -> %d\n", i, i + 1);
	}
}

int main_07_06() {

	int arr[ARR_LENGTH];
	unsigned short length = 0;

	puts("Insert array length (MAX 128):");
	scanf_s("%hu", &length);

	fillArray(arr, length);
	puts("");

	int subsetsCount = 1 << length;

	for (int i = 1; i <= subsetsCount; i++)
	{
		printf("[");
		for (int j = 0; j < length; j++)
		{
			if (i & (1 << j))
			{
				printf("%d", j + 1);
			}
		}
		puts("]");
	}
}