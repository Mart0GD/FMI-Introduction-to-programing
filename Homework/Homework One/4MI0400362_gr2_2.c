#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	unsigned int number;
	int result = scanf_s("%u", &number);

	if (result != 1){
		puts("invalid input!");
		return 1;
	}
	else if (number > 9999)
	{
		puts("Number out of range!");
		return 1;
	}

	srand(time(NULL));
	int largestDifference = 0;
	if (number < 10){
		puts("0");
	}
	else if (number < 100)
	{
		int secondDigit = number % 10;
		number /= 10;
		int firstDigit = number % 10;

		largestDifference = abs(secondDigit - firstDigit);
	}
	else if (number < 1000)
	{
		int thirdDigit = number % 10;
		number /= 10;
		int secondDigit = number % 10;
		number /= 10;
		int firstDigit = number % 10;

		int rndDigitOne = rand() % 3 + 1;
		int rndDigitTwo = rand() % 3 + 1;

		if (rndDigitOne == rndDigitTwo)
		{
			rndDigitTwo += 1 * (rndDigitOne == 1);
			rndDigitTwo -= 1 * (rndDigitOne == 3 || rndDigitOne != 1);
		}
		 
		printf("The random digits are -> %d %d\n", rndDigitOne, rndDigitTwo);
		int digitOneSelected = rndDigitOne == 1 || rndDigitTwo == 1;
		int digitTwoSelected = rndDigitOne == 2 || rndDigitTwo == 2;
		int digitThreeSelected = rndDigitOne == 3 || rndDigitTwo == 3;

		largestDifference = abs(abs(firstDigit * digitOneSelected - secondDigit * digitTwoSelected) - thirdDigit * digitThreeSelected);
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

		int rndDigitOne = rand() % 4 + 1;
		int rndDigitTwo = rand() % 4 + 1;

		if (rndDigitOne == rndDigitTwo)
		{
			rndDigitTwo += 1 * (rndDigitOne == 1);
			rndDigitTwo -= 1 * (rndDigitOne == 4 || rndDigitOne != 1);
		}

		printf("The random digits are -> %d %d\n", rndDigitOne, rndDigitTwo);
		int digitOneSelected = rndDigitOne == 1 || rndDigitTwo == 1;
		int digitTwoSelected = rndDigitOne == 2 || rndDigitTwo == 2;
		int digitThreeSelected = rndDigitOne == 3 || rndDigitTwo == 3;
		int digitFourSelected = rndDigitOne == 4 || rndDigitTwo == 4;

		largestDifference = abs(abs(abs(firstDigit * digitOneSelected - secondDigit * digitTwoSelected) - thirdDigit * digitThreeSelected) - (fourthDigit * digitFourSelected));
	}

	printf("The largest diffrence between the numbers is: %d", largestDifference);
	return 0;
}