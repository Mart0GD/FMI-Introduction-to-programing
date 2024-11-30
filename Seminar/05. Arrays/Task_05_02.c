#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
Задача 2: Напишете функция, която приема сортиран масив и елемент и връща индекса на елемента в масива, ако има такъв, и -1, в противен случай. (Binary search)
Вход: -8 5 22 23 44 100    -8, Изход: 0
Вход: -8 5 22 23 44 100    101, Изход: -1
*/

int binarySearch(const int arr[], const int numberToFind, const int arrLength) {

	int low = 0;
	int high = arrLength - 1;

	int mid = (low + high) / 2;
	int value = 0;
	while (low <= high)
	{
		value = arr[mid];

		if (value < numberToFind)
		{
			low = mid + 1;
		}
		else if (value > numberToFind)
		{
			high = mid - 1;
		}
		else if(value == numberToFind)
		{
			return mid;
		}

		mid = (low + high) / 2;
	}

	return -1;
}

int main_05_02() {
	int arr[MAX_ARR_LENGTH];
	int arrLength = 0;

	puts("Insert array size (max 128)");
	scanf_s("%d", &arrLength);
	fillArray(arr, arrLength);

	int numberToFind = 0;
	puts("Insert number to find!");
	scanf_s("%d", &numberToFind);

	int index = binarySearch(arr, numberToFind, arrLength);
	printf("Index -> %d", index);
}