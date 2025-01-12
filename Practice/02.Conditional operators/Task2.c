#include<stdio.h>

/*
Напишете програма, която прочита от конзолата цяло число и извежда дали:

дели се на 5 и 3 -> "divisible by 5 and 3"
дели се на 5 -> "divisible by 5"
дели се на 3 -> "divisible by 3"
не се дели и на 2те -> "not divisible by 5 or 3"
*/
int main2()
{
	int number;
	scanf_s("%d", &number);

	if (number % 3 == 0 && number % 5 == 0){
		printf("divisible by 5 and 3");
	}
	else if (number % 5 == 0){
		printf("divisible by 5");
	}
	else if (number % 3 == 0){
		printf("divisible by 3");
	}
	else {
		printf("not divisible by 5 or 3");
	}

	return 0;
}