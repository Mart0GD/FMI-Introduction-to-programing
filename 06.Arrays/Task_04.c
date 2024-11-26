#include<stdio.h>
#include<limits.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и после извежда числата в конзолата, които се повтарят.
*/
fillArray_04(const arr[], const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int isNumberInSeenArray(const int arr[], const int number, const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == number)
		{
			return 1;
		}
	}

	return 0;
}

void findAndPrintUniqueNumbersInArray(int arr[], const int arrLength)
{
	int seenNumbers[ARR_LENGTH] = { 0 };

	int position = 0;
	int seenNumbersLength = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (!isNumberInSeenArray(seenNumbers, arr[i], arrLength))
		{
			seenNumbers[position++] = arr[i];
			seenNumbersLength++;
		}
	}

	for (int i = 0; i < seenNumbersLength; i++)
	{
		printf("%d. -> %d\n", i + 1, seenNumbers[i]);
	}
}

int main_04()
{
	unsigned short n;
	int arr[ARR_LENGTH];
	scanf_s("%hu", &n);

	fillArray_04(arr, n);
	findAndPrintUniqueNumbersInArray(arr, n); // !functions should only be responsible for one thing!
	return 0;
}
