#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

/*
Задача 1: Да се напише функция, която приема символен низ и премахва от него всички символи, които не са цифри.
Вход: "jdhg81sgt37f1!#d466%", Изход: "81371466"
*/

int isNumber(const char chr) {
	return '0' <= chr && chr <= '9';
}

int main_08_01() {

	char* str = readText();

	int iter = 0;
	char* onlyNumbers = (char*)malloc(sizeof(char) * strlen(str));
	if (!onlyNumbers) return -1;

	while (*str != '\0'){
		if (isNumber(*str)) onlyNumbers[iter++] = *str;
		str++;
	}
	onlyNumbers[iter] = '\0';

	printf("%s", onlyNumbers);
	return 0;
}