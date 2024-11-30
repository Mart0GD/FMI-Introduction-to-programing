#include<stdio.h>
#define ARR_LENGTH 128
/*
Задача 1: Приема се масив, в който всяко число се среща два пъти, с изключение на едно число, което се среща точно веднъж. Напишете функция, която връща кое е това число.
❗ Използвайте побитови операции, за да постигнете линейно решение.
Вход: [9, 18, 9, -50, 12, 18, 15, 12, -50], Изход: 15
9 18 9 -50 12 18 15 12 -50
*/

void fillArray_01(int arr[], int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int findUniqueNumberInArray(const int arr[], int arrLength) {

	int uniqueNumber = 0;
	for (int i = 0; i < arrLength; i++)
	{
		uniqueNumber ^= arr[i];
	}

	return uniqueNumber;
}

int main_07_01() {
	int arrLength;
	int arr[ARR_LENGTH];

	scanf_s("%d", &arrLength);
	fillArray_01(arr, arrLength);

	int uniqueNumber = findUniqueNumberInArray(arr, arrLength);
	printf("Unique number -> %d", uniqueNumber);
	return 0;
}