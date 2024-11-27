#include<stdio.h>
#include<limits.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и после извежда числата в конзолата, които се повтарят.
*/

void fillArray_04(const arr[], const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void PrintArray(const int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d. -> %d\n", i + 1, arr[i]);
	}
}

int isNumberInArray(const int arr[], const int number, int startIndex, const int arrLength) {

	for (int i = startIndex; i < arrLength; i++)
	{
		if (arr[i] == number)
		{
			return 1;
		}
	}

	return 0;
}

void PrintSameNumbersInArray(int arr[], const int arrLength)
{
	int seenNumbers[ARR_LENGTH] = { 0 };

	int currentIndex = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (isNumberInArray(arr, arr[i], i + 1, arrLength) && !isNumberInArray(seenNumbers, arr[i], 0, arrLength))
		{
			seenNumbers[currentIndex] = arr[i];
			currentIndex++;
		}
	}

	PrintArray(seenNumbers, currentIndex);
}

int main()
{
	unsigned short n;
	int arr[ARR_LENGTH];
	scanf_s("%hu", &n);

	fillArray_04(arr, n);
	PrintSameNumbersInArray(arr, n);
}