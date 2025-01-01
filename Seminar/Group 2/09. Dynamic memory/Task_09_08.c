#include<stdio.h>
#include<stdlib.h>
#include "Functions2.h"
/*
Задача 8: Да се напише функция, която приема текст с произволна дължина. Всяко срещане на цифра да се замени с нейното наименувание. Масивът да се преоразмери с точна големина!
Вход: "Hello 9 today is 54 very0 good day."
Изход: "Hello nine today is fivefour veryzero good day."
*/

int isCurrentCharNumber(const char chr) {
	return chr >= '0' && chr <= '9';
}

void replaceWithWord(char** text, const char chr, int wordIndex, int matrixIndex, int* textLen) {
	char numbers[10][6] = {
		{"zero"},
		{"one"},
		{"two"},
		{"three"},
		{"four"},
		{"five"},
		{"six"},
		{"seven"},
		{"eight"},
		{"nine"},

	};


	char* currentNumberStringRep = numbers[matrixIndex];
	int currentNumberStringRepLen = strlen(numbers[matrixIndex]);
	int diff = currentNumberStringRepLen - 1;
	int newLen = *textLen + diff;
	*textLen = newLen;

	*text = (char*)realloc(*text, sizeof(char) * (newLen + 1));
	if (!*text) return NULL;
	for (int i = newLen; i > wordIndex; i--){
		(*text)[i] = (*text)[i - diff];
	}
	(*text)[newLen] = '\0';

	int iter = wordIndex;
	while (iter < wordIndex + currentNumberStringRepLen){
		(*text)[iter++] = *(currentNumberStringRep++);
	}
}

char* changeNumbersToWords(const char* text) {
	int textLen = strlen(text);
	char* newText = strcpy(text, textLen);

	int iter = 0;
	while (*newText != '\0'){
		if (isCurrentCharNumber(*newText)){
			for (int i = 0; i <= 9; i++){
				if (*newText - '0' == i) {
					newText -= iter;
					replaceWithWord(&newText, *newText, iter, i, &textLen);
					newText += iter;
				}
			}
		}

		newText++;iter++;
	}
	newText[iter] = '\0';

	return newText - iter;
}

int main_09_08() {
	char* text = readText();

	char* newText = changeNumbersToWords(text);
	int textLen = strlen(newText);

	for (int i = 0; i < textLen; i++){
		printf("%c", newText[i]);
	}

	free(text);
	free(newText);
	return 0;
}