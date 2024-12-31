#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

#define DISTANCE 'A' - 'a'
/*
������ 3: �� �� ������ �������, ����� ������ �������� ��� � ����������� ����� ����� �������� ����� �� ���� � ������.
����: "a1B2c@DeFg", �����: "A1B1C@DEFG"
*/

char toUpper(char chr) {
	if (chr >= 'a' && chr <= 'z')
		return  chr + DISTANCE;

	return chr;
}

int isLetter(char chr) {
	return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z');
}

int main_08_03() {
	char* str = readText();

	unsigned len = 0;
	while (*str != '\0') {
		if (isLetter(*str)) *(str) = toUpper(*str);
		str++;len++;
	}

	printf("%s", str - len);
	return 0;
}