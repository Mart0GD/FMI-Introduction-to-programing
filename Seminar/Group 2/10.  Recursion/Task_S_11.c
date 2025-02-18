#include "helper.h"

/*
Да се напише рекурсивна функция, която приема два символни низа и връща дали вторият е подниз на първия.
*/

int isPrefix(char* str, char* potentialInfix) {
	if (*potentialInfix == '\0') return 1;

	return *str == *potentialInfix && isPrefix(str + 1, potentialInfix + 1);
}

int infix(char* str, char* potentialInfix) {
	if (*str == '\0') {
		return *potentialInfix == '\0';
	}

	return isPrefix(str, potentialInfix) || infix(str + 1, potentialInfix);
}

int main_S_11() {

	char* str = readText();
	char* potentialInfix = readText();

	int isInfix = infix(str, potentialInfix);
	printf("%d", isInfix);
}