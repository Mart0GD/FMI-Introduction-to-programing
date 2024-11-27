#include<stdio.h>
#include<limits.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и намира началото и дължината на най-дългата растяща подредица.
*/

void FillArray_08(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int PrintMaxPositiveSequenceStartIndex(const int arr[], int arrLength)
{
	int maxSequenceLength = INT_MIN;
	int maxSequenceStartIndex = 0; 

	int currentSequenceLength = 0;
	for (int i = 0; i < arrLength; i++)
	{
		currentSequenceLength = 1;
		for (int j = i + 1; j < arrLength; j++)
		{
			if (arr[j - 1] < arr[j])
				currentSequenceLength++;
			else
				break;
		}

		if (currentSequenceLength > maxSequenceLength)
		{
			maxSequenceLength = currentSequenceLength;
			maxSequenceStartIndex = i;
		}
	}

	printf("Max sequence length -> %d\n", maxSequenceLength);
	printf("Max sequence start index -> %d", maxSequenceStartIndex);

	return 0;
}

int main_08()
{
	unsigned short n;
	int arr[ARR_LENGTH];
	scanf_s("%hu", &n);
	FillArray_08(arr, n);

	int maxSequenceIndex = PrintMaxPositiveSequenceStartIndex(arr, n);
	return 0;
}