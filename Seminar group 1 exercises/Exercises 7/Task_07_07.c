#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
7. Да се напише програма, която от даден масив получава нов, съдържащ всички елементи на първия, подредени в нарастващ ред и без повторения.
*/

int* createArr3(const unsigned arrSize) {

	int* arr = (int*)malloc(sizeof(int) * arrSize);	
	if (!arr) return NULL;

	for (int i = 0; i < arrSize; i++){
		scanf("%d", &arr[i]);
	}

	return arr;
}

int isSeen2(const int* arr, const int element, const unsigned arrSize) {

	for (int i = 0; i < arrSize; i++){
		if (arr[i] == element) return 1;
	}

	return 0;
}

void swap(int* arr, const unsigned index) {

	int temp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = temp;
}

void sort2(int* arr, const unsigned arrSize) {

	int swapped = 0;
	for (int i = 0; i < arrSize - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (arr[j] < arr[j + 1]) continue;
			swap(arr, j);
			swapped = 1;
		}

		if (!swapped) break;
	}
}

int* uniqueSort(const int* arr, const unsigned arrSize, unsigned* newArrSize) {
	int* newArr = (int*)malloc(sizeof(int) * arrSize);
	if (!newArr) return NULL;

	for (int i = 0; i < arrSize; i++){
		if (isSeen2(newArr, arr[i], *newArrSize)) continue;
		newArr[*newArrSize] = arr[i];
		*newArrSize += 1;
	}
	sort2(newArr, *newArrSize);

	return newArr;
}

int main_07_07() {
	unsigned arrSize;

	printf("Insert array size --> ");
	int res = scanf("%d", &arrSize);

	printf("Insert array values --> ");
	int* arr = createArr3(arrSize);

	int newArrSize = 0;
	int* newArr = uniqueSort(arr, arrSize, &newArrSize);

	puts("Sorted unique array: ");
	for (int i = 0; i < newArrSize; i++){
		printf("%d", newArr[i]);
	}

	free(arr);
	free(newArr);
	return 0;
}