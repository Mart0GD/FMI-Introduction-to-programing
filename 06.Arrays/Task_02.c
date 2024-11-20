#include<stdio.h>;
#include<limits.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и намира второто най-голямо число в масива.
*/

void fillArray_02(int arr[], const int numbersToRead)
{
	for (int i = 0; i < numbersToRead; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int getSecondBigestNumberInArray(const int arr[], const int arrLength)
{
	int biggestNumber = INT_MIN;
	int secondBiggestNumber = INT_MIN;

	for (int i = 0; i < arrLength; i++)
	{
		if (biggestNumber < arr[i]){ biggestNumber = arr[i]; }
	}

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < biggestNumber && arr[i] > secondBiggestNumber) { secondBiggestNumber = arr[i]; }
	}

	return secondBiggestNumber;
}

int main_02()
{
	unsigned short n;
	int arr[ARR_LENGTH] = {0};

	scanf_s("%hu", &n);

	fillArray_02(arr, n);
	int secondBiggestNumber = getSecondBigestNumberInArray(arr, n);

	printf("%d", secondBiggestNumber);
	return 0;
}