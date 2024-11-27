#include<stdio.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и проверява дали числата в масива образуват редица "трион".

Една редица ще наричаме трион, ако няма 3 последователни числа растящи/намаляващи числа.
*/

void fillArray_05(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int main_05()
{
	unsigned short n;
	unsigned int arr[ARR_LENGTH];
	scanf_s("%hu", &n);
	fillArray_05(arr, n);

	int isSequenceSaw = 1;
	int positiveProgress = 1;
	int negativeProgress = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			positiveProgress++;
			negativeProgress = 0;
		}
		else if (arr[i] < arr[i - 1])
		{
			negativeProgress++;
			positiveProgress = 0;
		}

		if (positiveProgress >= 3 || negativeProgress >= 3)
		{
			isSequenceSaw = 0;
			break;
		}
	}

	printf("The sequence is saw -> %d", isSequenceSaw);;
	return 0;
}