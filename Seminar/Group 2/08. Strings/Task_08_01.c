#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

/*
������ 1: �� �� ������ �������, ����� ������ �������� ��� � �������� �� ���� ������ �������, ����� �� �� �����.
����: "jdhg81sgt37f1!#d466%", �����: "81371466"
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