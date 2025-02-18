#include<stdio.h>
#include "helper.h"

/*
Задача 1: Да се напише рекурсивна функция, която приема низ и връща дължината му.
Вход: abcdcba, Изход: 7
*/


int strlenRec(char* text) {
	if (*text == '\0') return 0;

	return 1 + strlenRec(++text);
}

strlenRecWrapper(char* text) {

}

int main_S_01() {

	char* str = readText();

	int len = strlenRec(str);
	return 0;
}