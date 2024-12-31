#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)
/*
6. Даден е едномерен масив от цели числа a0, a1, ..., an-1. Да се напише програма, която сгъстява масива като изтрива последователните повтарящи се елементи и оставя по едно копие от тях.
*/

int* createArray2(const unsigned size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	if (!arr) { return NULL; }
	
	for (int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
		if (!arr[i]) return NULL;
	}

	return arr;
}

int isSeen(const int* arr, const int element, const unsigned arrSize) {
	for (int i = 0; i < arrSize; i++){
		if (arr[i] == element) return 1;
	}

	return 0;
}

int* getUniqueElements(const int* arr, const unsigned arrSize, unsigned* uniqueElementsSize) {

	int* uniqueElements = (int*)malloc(sizeof(int) * arrSize);

	for (int i = 0; i < arrSize; i++){
		if (isSeen(uniqueElements, arr[i], *uniqueElementsSize))
			continue;
		uniqueElements[*uniqueElementsSize] = arr[i];
		*uniqueElementsSize += 1;
	}

	return uniqueElements;
}

int main_07_06() {
	int arrSize = 0;

	printf("Array size --> ");
	int res = scanf("%d", &arrSize);

	if (res != 1){
		puts("Invalid input");
		return -1;
	}

	int* arr = createArray2(arrSize);

	int uniqueElementsSize = 0;
	int* uniqueElements = getUniqueElements(arr, arrSize, &uniqueElementsSize);

	for (int i = 0; i < uniqueElementsSize; i++){
		printf("%d ", uniqueElements[i]);
	}

	free(arr);
	free(uniqueElements);
	return 0;
}