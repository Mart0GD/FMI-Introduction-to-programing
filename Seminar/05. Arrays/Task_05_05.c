#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
Задача 5: Напишете функция, която намира най- дългия подмасив, съставен от еднакви числа (подмасивът се определя чрез индексите на началото и края си).
(Ако най- дългият подмасив не е уникален, да се изведат индексите на първия такъв.)
Вход: -8 22 22 22 44 44 -8 100 -8 -8, Изход: 1 3 (22 22 22)
Вход: 5 5 6 6 7 7 8 8, Изход: 0 1 (5 5)
Вход: 1 2 3 4 5, Изход: 0 0 (1)
*/
void fillArray_04(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void printLongestEqualSubSequence(const int arr[], const int arrLength) {

	int currentSubSequenceStartIndex = 0;
	int currentSequenceElements = 1;

	int longestSubSequenceStartIndex = -1;
	int longestSequenceElements = -1;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currentSequenceElements++;

			if (currentSubSequenceStartIndex != longestSubSequenceStartIndex && 
				currentSequenceElements > longestSequenceElements)
			{
				longestSubSequenceStartIndex = currentSubSequenceStartIndex;
				longestSequenceElements = currentSequenceElements;
			}
			continue;
		}

		currentSubSequenceStartIndex = i + 1;
		currentSequenceElements = 1;
		
	}

	printf("%d %d (", longestSubSequenceStartIndex, longestSubSequenceStartIndex + longestSequenceElements);

	for (int i = 0; i < longestSequenceElements; i++)
	{
		printf("% d", arr[longestSubSequenceStartIndex]);
	}
	printf(" )");
}

int main_05_05() {
	int arr[MAX_ARR_LENGTH];
	short arrLength = 0;

	puts("Insert sequence length: (MAX 128)");
	scanf_s("%hu", &arrLength);
	fillArray_04(arr, arrLength);

	printLongestEqualSubSequence(arr, arrLength);
	return 0;
}