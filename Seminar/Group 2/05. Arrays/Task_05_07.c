#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
Задача 7: Дадени са две числови редици. Да се напише функция, която проверява дали редиците са образувани от едни и същи множества.
Вход: 1 3 4 1 3     1 3 3 4 1 1 3, Изход: yes
Вход: 1 3 4 1 3     1 3 3 4 1 0 3, Изход: no
*/

void fillArray_06(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int contains(const int arr[], const int number, const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == number)
			return 1;
	}

	return 0;
}

int areArraysComposedOfSameNumberSets(int const arr1[], int const arr2[], const int arr1Length, const int arr2Length) {

	int seenNumbersInArray1[MAX_ARR_LENGTH];
	int seenNumbersInArray1Length = 0;

	int seenNumbersInArray2[MAX_ARR_LENGTH];
	int seenNumbersInArray2Length = 0;

	for (int i = 0; i < arr1Length; i++)
	{
		if (!contains(seenNumbersInArray1, arr1[i], seenNumbersInArray1Length))
		{
			seenNumbersInArray1[seenNumbersInArray1Length] = arr1[i];
			seenNumbersInArray1Length++;
		}
	}

	for (int i = 0; i < arr2Length; i++)
	{
		if (!contains(seenNumbersInArray2, arr2[i], seenNumbersInArray2Length))
		{
			seenNumbersInArray2[seenNumbersInArray2Length] = arr2[i];
			seenNumbersInArray2Length++;
		}
	}

	if (seenNumbersInArray1Length != seenNumbersInArray2Length) { return 0; }

	for (int i = 0; i < seenNumbersInArray1Length; i++)
	{
		if (!contains(arr2, arr1[i], arr2Length))
		{
			return 0;
		}
	}

	return 1;
}

int main_05_07() {

	int arr1[MAX_ARR_LENGTH];
	short arr1Length = 0;

	int arr2[MAX_ARR_LENGTH];
	short arr2Length = 0;

	puts("Insert first sequence length: (MAX 128)");
	scanf_s("%hu", &arr1Length);
	fillArray_03(arr1, arr1Length);

	puts("Insert second sequence length: (MAX 128)");
	scanf_s("%hu", &arr2Length);
	fillArray_06(arr2, arr2Length);

	printf("%s", areArraysComposedOfSameNumberSets(arr1, arr2, arr1Length, arr2Length) ? "yes" : "no");

}