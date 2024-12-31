#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

#define MAX_WORDS 1024
#define MAX_LETTERS 64

/*
Задача 5: Въвеждат се текст и две думи. За край на въвеждането на текста се счита символът за нов ред. За край на въвеждането на всяка дума се счита спейсът.
Реализирайте функция, която заменя всяко срещане на първата дума във въведения текст с втората дума.
Пример:
Вход:
"I am the best of the best."
"best"    "worst"
Изход:
"I am the worst of the worst."
*/

void freeWords(char** matrix, const unsigned size) {
	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}
	free(matrix);
}


char** split(const char* sentence, const char* splitters) {
	
	char** words = (char**)malloc(sizeof(char*) * MAX_WORDS);
	if (!words) return NULL;
	for (int i = 0; i < MAX_WORDS; i++){
		words[i] = (char*)malloc(sizeof(char) * MAX_LETTERS);
		if (!words[i]) {
			freeWords(words, i);
			return NULL;
		}
	}

	unsigned wordsCount = 0;
	unsigned currentSymbol = 0;
	while (*sentence != '\0'){
		if (strcts(splitters, *sentence)) {
			words[wordsCount++][currentSymbol] = '\0';
			sentence++;
			currentSymbol = 0;
			continue;
		}

		words[wordsCount][currentSymbol++] = *(sentence++);
	}
	words[wordsCount++][currentSymbol] = '\0';
	words[wordsCount][0] = '\0';

	return words;
}

int wordsLen(const char** words) {
	int len = 0;
	while (words[len][0] != '\0') {
		len++;
	}
	return len;
}

char* reallocateSentence(const char* arr, unsigned* buffer) {
	*buffer *= 2;
	char* newArr = (char*)realloc(arr, *buffer);
	if (!newArr) return NULL;

	return newArr;
}

char* join(const char** words, const unsigned wordsLen) {
	unsigned buffer = MAX_WORDS * MAX_LETTERS;

	char* cntchar = (char*)malloc(sizeof(char) * buffer);
	if (!cntchar) return NULL;

	int index = 0;
	int currentWordLen = 0;
	for (int i = 0; i < wordsLen; i++) {
		currentWordLen = strlen(words[i]);
		for (int j = 0; j < currentWordLen; j++){
			cntchar[index++] = words[i][j];
			if (index == buffer - 2) {
				cntchar = reallocateSentence(cntchar, &buffer);
				if (!cntchar) return NULL;
			}
		}
		if (i < wordsLen - 1) cntchar[index++] = ' ';
	}
	cntchar[index] = '\0';
	return cntchar;
}

char* replace(const char* sentence, const char* what, const char* with) {
	char splitters[] = {' ', '.', '\0'};
	char** words = split(sentence, splitters);

	int len = wordsLen(words);
	for (int i = 0; i < len; i++){
		if (equals(words[i], what)) {
			free(words[i]);
			words[i] = strcpy(with, strlen(with));
		}
	}

	char* newSentence = join(words, len);
	freeWords(words, MAX_WORDS);
	return newSentence;
}

int main_08_05() {
	char* sentence = readText();
	
	printf("Insert word to replace: ");
	char* what = readText();

	printf("Insert the new word: ");
	char* with = readText();

	char* newSentence = replace(sentence, what, with);
	printf("%s.", newSentence);


	free(what);
	free(with);
	free(sentence);
	free(newSentence);
	return 0;
}