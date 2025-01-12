#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

#define WORDS_BUFFER 128
#define LETTERS_BUFFER 64
/*
Задача 7: Да се напише функция, която приема низ и връща най-често срещаната дума в него (думите са разделени с произволен брой интервали, табулации и препинателни знаци). Функцията трябва да бъде case-insensitive (да третира главните и малки букви като еднакви).
Вход: "Me? Why always me?", Изход: me
*/

void freeCharMatrix(char** matrix, const unsigned size) {
	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}

	free(matrix);
}

char** createMatrix(const int rows, const int cols) {
	char** matrix = (char**)malloc(sizeof(char*) * rows);
	if (!matrix)
		return matrix;

	for (int i = 0; i < rows; i++){
		matrix[i] = (char*)malloc(sizeof(char) * cols);
		if (!matrix[i]) {
			freeCharMatrix(matrix, i);
			return NULL;
		}
	}

	return matrix;
}

void reallocateMatrix(char*** matrix, const int newSize) {
	char** reallocated = (char**)realloc(*matrix, sizeof(char*) * newSize);

	if (!reallocated) {
		puts("Failed to reallocate!");
		return;
	}
	*matrix = reallocated;
}

void toLower(char* chr) {
	const char distance = 'a' - 'A';

	if (*chr >= 'A' && *chr <= 'Z') {
		*chr += distance;
	}
}

int isWordChar(char chr) {
	return
		chr >= '0' && chr <= '9' ||
		chr >= 'a' && chr <= 'z' ||
		chr >= 'A' && chr <= 'Z' ||
		chr == '_';
}

void toLowerWord(char* arr) {
	int len = strlen(arr);

	while (*arr != '\0') {
		if (isWordChar(*arr)) toLower(arr);
		arr++;
	}

	arr -= len;
}

int containsWord(const char** matrix, const char* word, const unsigned size) {
	for (int i = 0; i < size; i++){
		if (equals(matrix[i], word)) {
			return 1;
		}
	}

	return 0;
}

char** unique(char** words, const unsigned size, int* uniqueSize) {
	char** unique = createMatrix(size, LETTERS_BUFFER);

	for (int i = 0; i < size; i++){
		if (!containsWord(unique, words[i],*uniqueSize)){
			unique[(*uniqueSize)++] = copyValues(words[i]);
		}
	}

	return unique;
}

char* findMostCommonWord(char** words, const unsigned size) {

	int uniqueSize = 0;
	char** uniqueWords = unique(words, size, &uniqueSize);
	int* uniqueWordsCount = (int*)calloc(uniqueSize, sizeof(int));

	for (int i = 0; i < size; i++){
		for (int j = 0; j < uniqueSize; j++){
			if (equals(uniqueWords[j], words[i])){
				uniqueWordsCount[j]++;
			}
		}
	}

	char* trend = NULL;

	int trendIndex = 0;
	int mostConjunctions = -1;
	for (int i = 0; i < uniqueSize; i++){
		if (uniqueWordsCount[i] > mostConjunctions){
			mostConjunctions = uniqueWordsCount[i];
			trendIndex = i;
		}
	}

	trend = copyValues(uniqueWords[trendIndex]);

	freeCharMatrix(uniqueWords, uniqueSize);
	free(uniqueWordsCount);
	return trend;
}

char* skipIntervals(char* text) {
	while (*text && !isWordChar(*text))
		text++;
	return text;
}

char* extractWord(char** start) {
	char* word = (char*)malloc(sizeof(char) * WORDS_BUFFER);
	if (!word)
		return NULL;

	int iter = 0;
	while (*(*start) && isWordChar(*(*start))){
		word[iter++] = (*((*start)++));
	}

	char* temp = (char*)realloc(word, sizeof(char) * (iter + 1));
	if (!temp)
		return word;
	word = temp;

	word[iter] = '\0';
	return word;
}

char* findTrend(char* arr) {
	int arrLen = strlen(arr);
	char* temp = copyValues(arr);
	toLowerWord(temp);

	int wordIndex = 0;
	char** words = createMatrix(WORDS_BUFFER, LETTERS_BUFFER);

	while (*temp && (*(temp = skipIntervals(temp)) != '\0')) 
		words[wordIndex++] = extractWord(&temp);

	reallocateMatrix(&words, wordIndex);

	char* trend = findMostCommonWord(words, wordIndex);

	freeCharMatrix(words, wordIndex);
	free(temp - arrLen);
	return trend;
}

int main_08_07() {

	char* sentence = readText();

	char* trend = findTrend(sentence);

	printf("the trend is --> %s", trend);
	return 0;
}