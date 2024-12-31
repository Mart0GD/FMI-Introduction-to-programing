#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
Задача 4: Ще казваме, че подредица от числа е трион, ако всяко число в нея е едновременно по- голямо или равно на двата си съседа или едновременно по- малко или равно на тях.
За първия и последния елемент имаме само по един съсед.
Напишете функция, която приема масив от цели числа и ги пренарежда така, че да образуват поредица трион.
Вход: 1 5 1 0 3, Изход: 1 5 0 3 1
Вход: 10 -10 -22 11 18, Изход: 10 -22 11 -10 18

Zab| -> tuk poglednah reshenieto, izobshto ne se bqh setil
*/

void fillArray_03(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void printSequence(const int arr[], const int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(int arr[], int num1Index, int num2Index) {
	int temp = arr[num1Index];

	arr[num1Index] = arr[num2Index];
	arr[num2Index] = temp;
}

void convertSequenceToSaw(int arr[], const int arrLength)
{
	
	for (int i = 1; i < arrLength - 1; i++)
	{
		if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1] || arr[i - 1] > arr[i] && arr[i] > arr[i + 1])
		{
			swap(arr, i, i + 1);
		}
		
	}
}

int main_05_04()
{
	int arr[MAX_ARR_LENGTH];
	short arrLength = 0;

	puts("Insert sequence length: (MAX 128)");
	scanf_s("%hu", &arrLength);
	fillArray_03(arr, arrLength);

	convertSequenceToSaw(arr, arrLength);

	printSequence(arr, arrLength);
	return 0;
}