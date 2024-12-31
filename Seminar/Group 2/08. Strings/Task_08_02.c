#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
/*
Задача 2: Да се напише функция, която приема символен низ, премахва от него всички символи, които не са цифри, и връща като резултат числото, което се образува от тези цифри.
Вход: "jdhg81sgt37f1!#d466%", Изход: 81371466
*/

long long unsigned parse(char* str) {
	long long unsigned number = 0;
	while (*str != '\0'){
		number *= 10;
		number += *str - '0';
		str++;
	}

	return number;
}

int main_08_02() {

	char* text = readText();

	unsigned iter = 0;
	char* onlyNumbers = (char*)malloc(sizeof(char) * strlen(text));
	while (*(text) != '\0'){
		if ('0' <= *text && *text <= '9') onlyNumbers[iter++] = *text;
		text++;
	}
	onlyNumbers[iter] = '\0';

	long long unsigned number = parse(onlyNumbers);
	printf("%llu", number);
	return 0;
}