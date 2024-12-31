#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

/*
������ 6: �� �� ������ �������, ����� ������ ��� � ����� ���� �� ������ � ���� (������ �� ��������� � ���������� ���� ���������, ��������� � ������������ �����). ������� ���� ������� ���������� �����, ����� � ����� �����.
����: "Me? Why always me?", �����: 4
*/

int isCharValid(char  chr) {
	return
		chr >= '0' && chr <= '9' ||
		chr >= 'a' && chr <= 'z' ||
		chr >= 'A' && chr <= 'Z' ||
		chr == '_';
}

int wordsCount(char* sentence) {
	int words = 0;

	int wordStarted = 0;
	while (*sentence != '\0'){
		if (!wordStarted && isCharValid(*sentence)){
			wordStarted = 1;
		}
		else if (wordStarted && !isCharValid(*sentence)) {
			wordStarted = 0;
			words++;
		}

		sentence++;
	}

	return words;
}

int main_08_06() {

	char* sentence = readText();

	int count = wordsCount(sentence);
	printf("The count of all words is --> %d", count);
	return 0;
}