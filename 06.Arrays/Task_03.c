#include<stdio.h>
#define ARR_LENGTH 128
/*
Ќапишете програма, ко€то прочита от конзолата ц€ло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив, извежда средно аритметичното на четните числа на конзолата и умножава сбора на четните и този на нечетните числа.
*/

void fillArray_3(int arr[], const int numbersToRead)
{
	for (int i = 0; i < numbersToRead; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void printAverageOfEvenNumbersInArray(const int arr[], const int arrLength)
{
	double sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 == 0) { sum += arr[i]; }
	}

	printf("Average of evens -> %lf\n", sum / arrLength);
}

void printSumOfEvensMultipliedBySumOfOdds(const int arr[], const int arrLength)
{
	int evenSum = 0;
	int oddSum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 == 0){
			evenSum += arr[i];
		}
		else{
			oddSum += arr[i];
		}
	}

	printf("Sum of evens * odds -> %d\n", evenSum * oddSum);
}

int main_03()
{
	unsigned short n;
	int arr[ARR_LENGTH] = {0};
	scanf_s("%hu", &n);

	fillArray_3(arr, n);

	printAverageOfEvenNumbersInArray(arr, n);
	printSumOfEvensMultipliedBySumOfOdds(arr, n);
	return 0;
}