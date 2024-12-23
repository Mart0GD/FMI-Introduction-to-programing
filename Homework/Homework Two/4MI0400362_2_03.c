#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

#define MAX_NUMBERS_COUNT 100
#define MAX_INTERVALS_COUNT 100

int readNumbersArray(int arr[], const unsigned arrSize) {

	for (int i = 0; i < arrSize; i++) {

		if (scanf("%d", &arr[i]) != 1) {
			puts("Inavlid input!");
			return 0;
		}
	}

	return 1;
}

int readIntervals(unsigned arr[], const unsigned arrSize, const unsigned maxIntervalValue) {
	
	for (int i = 0; i < arrSize; i++){

		printf("Insert interval: [a,b] --> ");

		if (scanf("%u %u", &arr[i++], &arr[i]) != 2) {
			puts("Inavlid input!");
			return 0;
		}
		else if (arr[i] < arr[i - 1]) {
			puts("Invalid input a should be bigger than b!");
			i--;
			continue;
		}
		else if (arr[i] > maxIntervalValue)
		{
			printf("Interval value cannot exceed -> %d\n", maxIntervalValue);
			i--;
			continue;
		}
	}

	return 1;
}

void printNumbers(const int numbersArr[], const unsigned arrSize) {

	for (int i = 0; i < arrSize; i++)
	{
		printf("%d", numbersArr[i]);
	}
	puts("");
}

void sortIntervalsDescending(unsigned intervals[], const int numbers[], const unsigned intervalsCount, const unsigned numbersCount) {

	int countOfElementsInIntervals[MAX_INTERVALS_COUNT] = { 0 };
	for (int i = 0; i < intervalsCount; i++)
	{
		for (int j = 0; j < numbersCount; j++)
		{
			if (intervals[i * 2] <= numbers[j] && intervals[i * 2 + 1] >= numbers[j])
			{
				countOfElementsInIntervals[i]++;
			}
		}
	}

	int swapped = 0;
	unsigned temp;
	for (int i = 0; i < intervalsCount - 1; i++)
	{
		for (int j = 0; j < intervalsCount - i - 1; j++)
		{
			if (countOfElementsInIntervals[j] > countOfElementsInIntervals[j + 1]) continue;

			temp = countOfElementsInIntervals[j];
			countOfElementsInIntervals[j] = countOfElementsInIntervals[j + 1];
			countOfElementsInIntervals[j + 1] = temp;

			temp = intervals[j * 2];
			intervals[j * 2] = intervals[(j + 1) * 2];
			intervals[(j + 1) * 2] = temp;

			temp = intervals[j * 2 + 1];
			intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
			intervals[(j + 1) * 2 + 1] = temp;
			swapped = 1;
		}

		if (!swapped) break;
	}
}

void reverse(int numbers[], unsigned startIndex, unsigned endIndex) {

	int temp;
	while (endIndex > startIndex){
		temp = numbers[startIndex];
		numbers[startIndex] = numbers[endIndex];
		numbers[endIndex] = temp;

		startIndex++;endIndex--;
	}
}

void reverseNumbersInSortedIntervals(const unsigned soretdIntervals[], int numbers[], const unsigned intervalsCount, const unsigned numbersCount){
	
	for (int i = 0; i < intervalsCount; i++){
		reverse(numbers, soretdIntervals[i * 2], soretdIntervals[i * 2 + 1]);

		printf("Numbers after reversing indexes [%d,%d]: \n", soretdIntervals[i * 2], soretdIntervals[i * 2 + 1]);
		printNumbers(numbers, numbersCount);
		puts("");
	}
}

int main() {

	unsigned numbersCount, intervalsCount;

	printf("Insert count of expected numbers --> ");
	if (scanf("%u", &numbersCount) != 1 || numbersCount > MAX_NUMBERS_COUNT) {
		puts("invalid input!");
		return -1;
	}

	printf("Insert intervals count --> ");
	if (scanf("%u", &intervalsCount) != 1 || intervalsCount > MAX_INTERVALS_COUNT) {
		puts("Invalid input!");
		return -1;
	}

	int numbersArray[MAX_NUMBERS_COUNT];
	unsigned intervalsArray[MAX_INTERVALS_COUNT];

	puts("Insert numbers: ");
	if(!readNumbersArray(numbersArray, numbersCount)) return - 1;
	if(!readIntervals(intervalsArray, intervalsCount * 2, numbersCount - 1)) return -1;

	sortIntervalsDescending(intervalsArray, numbersArray, intervalsCount, numbersCount);

	puts("\nOriginal numbers: ");
	printNumbers(numbersArray, numbersCount);
	puts("");

	reverseNumbersInSortedIntervals(intervalsArray, numbersArray, intervalsCount, numbersCount);
	return 0;
}



