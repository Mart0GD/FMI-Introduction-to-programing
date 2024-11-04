#include<stdio.h>
#include<math.h>

int main2()
{
	unsigned int number;
	int result = scanf_s("%u", &number);

	if (result != 1 || number > 9999){
		puts("invalid input!");
		return 1;
	}

	int largestDiffrence = 0;
	if (number < 10){
		puts("no diffrence can be calculated in a single digit number!");
		return 1;
	}
	else if (number < 100)
	{
		int secondDigit = number % 10;
		number /= 10;
		int firstDigit = number % 10;

		largestDiffrence = abs(firstDigit - secondDigit);
	}
	else if (number < 1000)
	{
		int thirdDigit = number % 10;
		number /= 10;
		int secondDigit = number % 10;
		number /= 10;
		int firstDigit = number % 10;

		int firstDiff = abs(firstDigit - thirdDigit);
		int secondDiff = abs(secondDigit - thirdDigit);
		int thirdDiff = abs(firstDigit - secondDigit);

		int FirstDiffBiggerThanSecond = firstDiff > secondDiff;
		int biggerDiff = firstDiff * FirstDiffBiggerThanSecond + !(FirstDiffBiggerThanSecond) * secondDiff;

		largestDiffrence = biggerDiff > thirdDiff ? biggerDiff : thirdDiff;
	}
	else
	{
		int fourthDigit = number % 10;
		number /= 10;
		int thirdDigit = number % 10;
		number /= 10;
		int secondDigit = number % 10;
		number /= 10;
		int firstDigit = number % 10;

		int firstDiff = abs(firstDigit - secondDigit);
		int secondDiff = abs(firstDigit - thirdDigit);
		int thirdDiff = abs(firstDigit - fourthDigit);

		int fourthDiff = abs(secondDigit - thirdDigit);
		int fifthDiff = abs(secondDigit - fourthDigit);
		int sixthDiff = abs(thirdDigit - fourthDigit);

		int FirstDiffBiggerThanSecond = firstDiff > secondDiff;
		int biggestFromTheFirstThree = firstDiff * FirstDiffBiggerThanSecond + !(FirstDiffBiggerThanSecond)*secondDiff;

		int fourthDiffBiggerThenFifth = fourthDiff > fifthDiff;
		int biggerFromTheSecondThree = fourthDiff * fourthDiffBiggerThenFifth + !(fourthDiffBiggerThenFifth) * fifthDiff;

		largestDiffrence = biggestFromTheFirstThree > biggerFromTheSecondThree ? biggestFromTheFirstThree : biggerFromTheSecondThree;
	}

	printf("The largest diffrence between the numbers is: %d", largestDiffrence);
	return 0;
}