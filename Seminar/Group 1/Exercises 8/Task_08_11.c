#include<stdio.h>
#include "helpers.h"

#pragma warning(disable: 4996)

/*
-> �������� ��������, ����� ��������� ����� �� �������� �������:
- ���� '.', '!', '?' ��� '...' � ������ ������ ���������� ����� ������ �� � ������ (������ �� ���������)
- ��� ���� ����� ����� ��� ������, �� �� ������ �������� ����� ����� � �������� �� ����� ����� (ThisIsAText -> This is a text)
- ��������� �� ������������ �� �� ������� � ���������. ������ ����������������� �� ������ �� ���� ������ ������ �� �� ������� � ���� ��������.
*/

int isEndOfSentenceSymbol(const char chr) {
	return
		chr == '?' ||
		chr == '!' ||
		chr == '.';
}

int isUpper(const char chr) {
	return chr >= 'A' && chr <= 'Z';
}

int isLower(const char chr) {
	return chr >= 'a' && chr <= 'z';
}

char* format(const char* text) {
	if (!text) return NULL;

	char* formated = (char*)malloc(strlen(text) * 2 + 1);
	if (!formated) return formated;

	int iter = 0;
	while (*text){
		if (*text == '_' && formated[iter - 1] != ' ') formated[iter++] = ' ';
		else if (*text == ' ' && formated[iter - 1] == ' ') {} // do nothing
		else if (isEndOfSentenceSymbol(*text)) {
			
			if (*text == '.' && *(text + 1) == '.' && *(text + 2) == '.') {
				formated[iter++] = *(text++);
				formated[iter++] = *(text++);
			}
			formated[iter++] = *(text++);
			
			if (isLower(*text)) { formated[iter++] = *text - 32; }
			else formated[iter++] = *text;
		}
		else if (isUpper(*text) && isLower(formated[iter - 1])) {
			formated[iter++] = ' ';
			formated[iter++] = *text + 32;
		}
		else formated[iter++] = *text;

		text++;
	}

	char* temp = (char*)realloc(formated, iter + 1);
	if (!temp) return formated;
	formated = temp;
	formated[iter] = '\0';

	return formated;
}

int main_08_11() {

	char* text = readText();

	char* formatted = format(text);
	printf("Formated --> %s", formatted);

	free(formatted);
	free(text);
	return 0;
}