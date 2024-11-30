#include<stdio.h>
#include<limits.h>
/*
Задача 4: Да се напише функция, която приема цяло положително число n и връща дължината на най-дългата поредица от последователни растящи цифри в него.
Вход: 781234489, Изход: 4 (1234)
*/

long long reverseNumber_2(long long number) {
	long long reversed = 0;
	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}

int getSubsetLength(int subset) {

	int length = 0;
	while (subset != 0)
	{
		subset /= 10;
		length++;
	}

	return length;
}

long long getLongestPositiveContinuousSubset(long long number) {

	number = reverseNumber_2(number);
	int previousDigit = number % 10;
	number /= 10;
	int currentDigit = 0;

	long long currentSubset = previousDigit;
	int currentSubsetLength = 1;

	long long longestSubset = 0;
	int longestSubsetLength = INT_MIN;
	while (number != 0)
	{
		currentDigit = number % 10;
		number /= 10;

		if (currentDigit >= previousDigit){
			currentSubset *= 10;
			currentSubset += currentDigit;

			currentSubsetLength++;

			if (currentSubsetLength > longestSubsetLength)
			{
				longestSubset = currentSubset;
				longestSubsetLength = currentSubsetLength;
			}
		}
		else{
			currentSubset = currentDigit;
			currentSubsetLength = 1;
		}
		previousDigit = currentDigit;
	}

	return longestSubset;
}

int main_04_04()
{
	long long number = 0;
	scanf_s("%lld", &number);

	long long longestPositiveContinuousSubset = getLongestPositiveContinuousSubset(number);
	printf("Longest subset -> %lld", longestPositiveContinuousSubset);
	return 0;
}