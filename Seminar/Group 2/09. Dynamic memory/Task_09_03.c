#include<stdio.h>
#include<stdlib.h>
#include "Functions2.h"
/*
Задача 3: Да се напише функция, която приема низ и връща нов низ, в който са премахнати всички цифри от първия. Новият низ да бъде с точна дължина!
Вход: "i1v2an345cho", Изход: "ivancho"
*/

int isDigit(char chr) {
	return chr >= '0' && chr <= '9';
}

char* removeDigits(char* text) {
	char* newText = (char*)malloc(sizeof(char) * strlen(text));
	if (!newText) return NULL;

	int iter = 0;
	while (*text != '\0'){
		if (!isDigit(*text)){
			newText[iter++] = *text;
		}

		text++;
	}
	newText[iter] = '\0';

	return newText;
}

int main_09_03() {

	char* text = readText();
	char* onlyLetters = removeDigits(text);

	printf("%s", onlyLetters);
	return 0;
}