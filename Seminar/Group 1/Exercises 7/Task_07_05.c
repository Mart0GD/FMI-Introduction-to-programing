#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

//Да се напише програма, която слива два сортирани в нарастващ ред масиви в нов сортиран масив.

int* createArray(unsigned size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	if (!arr) return NULL;

	for (int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}

	return arr;
}

void printArr2(const int* arr, const unsigned arrSize) {
	for (int i = 0; i < arrSize; i++){
		printf("%d", arr[i]);
	}
}

int* mergeSort(const int* arr1, const int* arr2, const unsigned arr1Size, const unsigned arr2Size) {
	int* mergedArr = (int*)malloc(sizeof(int) * (arr1Size + arr2Size));
	if (!mergedArr) return NULL;

	unsigned arr1Index = 0, arr2Index = 0, mergedIndex = 0;
	while (arr1Index != arr1Size && arr2Index != arr1Size){

		if (arr1[arr1Index] > arr2[arr2Index]){
			mergedArr[mergedIndex++] = arr2[arr2Index++];
		}
		else if (arr1[arr1Index] < arr2[arr2Index]){
			mergedArr[mergedIndex++] = arr1[arr1Index++];
		}
		else{
			mergedArr[mergedIndex++] = arr1[arr1Index++];
			mergedArr[mergedIndex++] = arr2[arr2Index++];
		}
	}

	while (arr1Index < arr1Size)
		mergedArr[mergedIndex++] = arr1[arr1Index++];

	while (arr2Index < arr2Size)
		mergedArr[mergedIndex++] = arr2[arr2Index++];


	return mergedArr;
}

int main_07_05() {
	unsigned arr1Size, arr2Size;

	printf("Insert first array and second array sizes --> ");
	scanf("%u %u", &arr1Size, &arr2Size);

	puts("Insert ascending sorted values: ");
	int* arr1 = createArray(arr1Size);

	puts("Insert ascending sorted values: ");
	int* arr2 = createArray(arr2Size);

	int* mergedArr = mergeSort(arr1, arr2, arr1Size, arr2Size);

	printArr2(mergedArr, arr1Size + arr2Size);
	free(arr1);
	free(arr2);
	free(mergedArr);
	return 0;
}