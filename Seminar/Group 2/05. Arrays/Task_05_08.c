#include<stdio.h>
#define MAX_ARR_LENGTH 128

/*
Задача 8: Напишете функция, която приема масив от цели числа и пренарежда елементите му така, че на първо място да стои най-големият, след него – най-малкият, след това – вторият най-голям и т.н.
Вход: 5 2 1 6 7 4, Изход: 7 1 6 2 5 4
*/

void fillArray_07(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void swapValues(int arr[], const int indexOne, const int indexTwo) {
	int temp = arr[indexOne];

	arr[indexOne] = arr[indexTwo];
	arr[indexTwo] = temp;
}

void sortArrayAscending(int arrToSort[], const int arrLength) {

	int index = 0;
	int isSwaped = 0;
	for (int i = 0; i <= arrLength - 1; i++)
	{
		isSwaped = 0;
		for (int j = 0; j < arrLength - 1 - i; j++)
		{
			if (arrToSort[j] > arrToSort[j + 1])
			{
				swapValues(arrToSort, j, j + 1);
				isSwaped = 1;
			}
		}

		if (!isSwaped)
		{
			break;
		}
	}
}

void copyReverseSortedArray(int resultArr[], const int sortedArr[], const int arrLength) {

	int index = 0;
	for (int i = arrLength - 1; i >= 0; i--)
	{
		resultArr[index] = sortedArr[i];
		index++;
	}
}

void printArrayZigZag(const int arrAscending[], const int arrDescending[], int arrLength) {

	int ascIndex = 0;
	int descIndex = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", arrDescending[descIndex]);
			descIndex++;
			continue;
		}

		printf("%d ", arrAscending[ascIndex]);
		ascIndex++;
		
	}
}

int main_05_08()
{
	int arr[MAX_ARR_LENGTH];
	int arrLength = 0;
	scanf_s("%d", &arrLength);
	fillArray_07(arr, arrLength);

	int arrayDescending[MAX_ARR_LENGTH];

	sortArrayAscending(arr, arrLength);
	copyReverseSortedArray(arrayDescending, arr, arrLength);

	printArrayZigZag(arr, arrayDescending, arrLength);
}