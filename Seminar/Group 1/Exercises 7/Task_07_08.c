#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
8. Дадени са три сортирани във възходящ ред едномерни масиви a, b, c. Да се напише програма, която определя броя на равенствата ai = bj = ck, където ai, bj и ck са елементи на масивите a, b и c съответно.
*/

int* createArray4(const unsigned arrSize) {
	int* arr = (int*)malloc(sizeof(int) * arrSize);
	if (!arr) return NULL;

	for (int i = 0; i < arrSize; i++){
		scanf("%d", &arr[i]);
	}

	return arr;
}

int findEqualities(const int* arr1, const int* arr2, const int* arr3, const unsigned arr1Size, const unsigned arr2Size, const unsigned arr3Size) {

	int counter = 0;
	unsigned index1 = 0, index2 = 0, index3 = 0;
	while (index1 < arr1Size && index2 < arr2Size && index3 < arr3Size){

		if (arr1[index1] < arr2[index2]) { index1++; }
		else if (arr1[index1] > arr2[index2]) { index2++; }
		else if (arr2[index2] < arr3[index3]) { index2++; }
		else if (arr2[index2] > arr3[index3]) { index3++; }
		else {
			counter++;
			index1++;index2++;index3++;
		}
	}

	return counter;
}

int main_07_08() {
	unsigned arr1Size, arr2Size, arr3Size;

	puts("Insert array one two and three sizes: ");
	scanf("%u %u %u", &arr1Size, &arr2Size, &arr3Size);

	puts("Insert arrays: ");
	int* arr1 = createArray4(arr1Size);
	int* arr2 = createArray4(arr2Size);
	int* arr3 = createArray4(arr3Size);

	int equalities = findEqualities(arr1, arr2, arr3, arr1Size, arr2Size, arr3Size);

	printf("The number of equalities is --> %d", equalities);
	free(arr1);
	free(arr2);
	free(arr3);
	return 0;
}