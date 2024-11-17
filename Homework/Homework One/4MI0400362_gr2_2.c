#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	unsigned int number;
	int result = scanf_s("%d", &number);

	if (result != 1){
		puts("invalid input!");
		return 1;
	}
	else if (number > 9999)
	{
		puts("Number out of range!");
		return 1;
	}
	else if (number < 10)
	{
		puts("No difference can be calculated in single digit number!");
		return 1;
	}

	int digitOne = (number / 1000) % 10;
	int digitTwo = (number / 100) % 10;
	int digitThree = (number / 10) % 10;;
	int digitFour = number % 10;

	int maxNumber = -1;
	if (number >= 1000 && digitOne > maxNumber) maxNumber = digitOne;
	if (number >= 100 && digitTwo > maxNumber) maxNumber = digitTwo;
	if (number >= 10 && digitThree > maxNumber) maxNumber = digitThree;
	if (digitFour > maxNumber) maxNumber = digitFour;

	int minNumber = 10;
	if (number >= 1000 && digitOne < minNumber) minNumber = digitOne;
	if (number >= 100 && digitTwo < minNumber) minNumber = digitTwo;
	if (number >= 10 && digitThree < minNumber) minNumber = digitThree;
	if (digitFour < minNumber) minNumber = digitFour;

	printf("The largest diffrence between the numbers is: %d", maxNumber - minNumber);
	return 0;
}
