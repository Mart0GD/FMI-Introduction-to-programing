#include<stdio.h>

/*
Задача 4: Да се напише програма, която при въведено цяло положително число n отпечатва дали числото е палиндром.
Вход: 34543, Изход: 1
Вход: 111, Изход: 1
Вход: 12345, Изход: 0
*/
int main_04_05()
{
	int number = 0;
	scanf_s("%d", &number);

	int numberCopy = number;
	int numberReversed = 0;
	while (numberCopy != 0)
	{
		numberReversed *= 10;
		numberReversed += numberCopy % 10;
		numberCopy /= 10;
	}

	if (number == numberReversed){
		puts("1");
	}
	else{
		puts("0");
	}


	return 0;
}