#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
Задача 6: Да се напише функция, която обединява два сортирани динамични масива, като резултатният масив остава сортиран. Последният да е с точна големина!
Вход: [1 3 5 10 21]    [2 7 12 32], Изход: [1 2 3 5 7 10 12 21 32]
*/

int* createSortedArr(const unsigned size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	if (!arr) return NULL;

	puts("insert arr: ");
	for (int i = 0; i < size; i++){
		scanf("%u", &arr[i]);
	}

	return arr;
}

int* merge(int* arr1, int* arr2, const unsigned size1, const unsigned size2) {
	
	int* mergedArr = (int*)malloc(sizeof(int) * (size1 + size2));

	int iter = 0;
	int index1 = 0;
	int index2 = 0;
	while (index1 < size1 && index2 < size2) {
		if (arr1[index1] < arr2[index2]) {
			mergedArr[iter++] = arr1[index1++];
		}
		else if (arr1[index1] > arr2[index2]) {
			mergedArr[iter++] = arr2[index2++];
		}
		else {
			mergedArr[iter++] = arr1[index1++];
			mergedArr[iter++] = arr2[index2++];
		}
	}

	while (index1 < size1){
		mergedArr[iter++] = arr1[index1++];
	}
	while (index2 < size2) {
		mergedArr[iter++] = arr1[index2++];
	}

	return mergedArr;
}

int main_09_06() {

	unsigned size1, size2;

	printf("Insert arr one ane two sizes: ");
	scanf("%u %u", &size1, &size2);

	int* arr1 = createSortedArr(size1);
	int* arr2 = createSortedArr(size2);

	int* merged = merge(arr1, arr2, size1, size2);

	for (int i = 0; i < size1 + size2; i++){
		printf("%d ", merged[i]);
	}
	return 0;
}