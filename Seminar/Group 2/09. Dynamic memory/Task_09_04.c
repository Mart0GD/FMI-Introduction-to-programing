#include<stdio.h>
#include<stdlib.h>
#include "Functions2.h"
/*
������ 4: �� �� ������ �������, ����� ������ ��� � ����� ��� ���� ���� uppercaseStr � lowercaseStr ������ ��:
uppercaseStr ������� ���� �������� ����� �� ��������� ���,
lowercaseStr ������� ���� ������� ����� �� ��������� ���.
���������� ������� �� ���������. uppercaseStr � lowercaseStr �� ����� � ����� �������!
����: "I am the best Player"
�����: "IP"     "amthebestlayer"
*/

int isUpper(char chr) {
	return chr >= 'A' && chr <= 'Z';
}

int isLower(char chr) {
	return chr >= 'a' && chr <= 'z';
}

char* getLowercaseLetters(const char* text) {
	char* lowercase = (char*)malloc(sizeof(char) * strlen(text));

	int iter = 0;
	while (*text != '\0'){
		if (isLower(*text)){
			lowercase[iter++] = *text;
		}
		text++;
	}
	lowercase[iter] = '\0';

	return lowercase;
}

char* getUpercaseLetters(const char* text) {
	char* upperCase = (char*)malloc(sizeof(char) * strlen(text));

	int iter = 0;
	while (*text != '\0') {
		if (isUpper(*text)) {
			upperCase[iter++] = *text;
		}
		text++;
	}
	upperCase[iter] = '\0';

	return upperCase;
}

int main_09_04() {

	char* text = readText();

	char* onlyLower = getLowercaseLetters(text);
	char* onlyUpper = getUpercaseLetters(text);

	printf("Uppercase --> %s\n", onlyUpper);
	printf("Lowercase --> %s", onlyLower);
	return 0;
}