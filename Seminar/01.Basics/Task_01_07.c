#include<stdio.h>

//Задача 7: Въвежа се символ. Да се отпечата 1, ако е английска гласна буква, и 0, ако не е.
int main01_7() {

	char letter;
	scanf_s("%c", &letter);

	int minLowercase = 'a';
	int maxLowercase = 'z';

	int minUppercase = 'A';
	int maxUppercase = 'Z';

	printf("%d", (letter >= minLowercase && letter <= maxLowercase) || (letter >= minUppercase && letter <= maxUppercase));
	return 0;
}