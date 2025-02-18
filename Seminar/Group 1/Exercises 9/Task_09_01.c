#include<stdio.h>
#include<stdlib.h>

/*
Задача 1. Да се дефинира рекурсивна функция, която променя дадено естествено число като заменя всяко срещане на дадена цифра в него с друга.
*/

int changeNumber(int number, int numberToReplace, int replacer) {
	if (number == 0) {
		return  0;
	}

	int lastDigit = number % 10 == numberToReplace 
					? replacer
					: number % 10;


	return changeNumber(number / 10, numberToReplace, replacer) * 10 + lastDigit;
}

int main_09_01() {

	int number = 19;
	int changed = changeNumber(number, 9, 8);
}