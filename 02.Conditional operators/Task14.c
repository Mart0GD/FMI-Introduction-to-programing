#include<stdio.h>
#include<math.h>

/*
Напишете програма, която прочита едно цяло число и определя дали то може да бъде записано като квадрат на друго цяло число. Ако числото е точен квадрат, 
изведете „perfect square“, в противен случай „not a perfect square“.
*/
int main14()
{
	int number;
	scanf_s("%d", &number);

	int numberSquared = sqrt(number);
	int isNumberPerfectSquare = numberSquared * numberSquared == number;

	printf("%s", isNumberPerfectSquare ? "Yes" : "No");

}