#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

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

	char** unique = (char**)malloc(sizeof(char*) * size);
	if (!unique) return NULL;
	for (int i = 0; i < size; i++){
		unique[i] = (char*)malloc(sizeof(char) * size);
		if (!unique[i]) {
			freeCharMatrix(unique, i);
			return NULL;
		}
	}

	int index = 0;
	for (int i = 0; i < size; i++){
		if (!containsWord(unique, words[i],index)){
			free(unique[index]);
			unique[index++] = strcpy(words[i], strlen(words[i]));
		}
	}

	*uniqueSize = index;
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
	int mostConjunctions = -1;
	for (int i = 0; i < uniqueSize; i++){
		if (uniqueWordsCount[i] > mostConjunctions){
			mostConjunctions = uniqueWordsCount[i];
			trend = strcpy(uniqueWords[i], strlen(uniqueWords[i]));
		}
	}

	freeCharMatrix(uniqueWords, uniqueSize);
	free(uniqueWordsCount);
	return trend;
}

char* findTrend(char* arr) {
	int arrLen = strlen(arr);
	char* temp = strcpy(arr, arrLen);
	toLowerWord(temp);

	int wordIndex = 0;
	char** words = (char**)malloc(sizeof(char*) * arrLen);
	if (!words) return NULL;

	for (int i = 0; i < arrLen; i++){
		words[i] = (char*)malloc(sizeof(char) * arrLen);
		if (!words[i]) {
			freeCharMatrix(words, i);
			return NULL;
		}
	}

	char* trend = NULL;
	int iter = 0;
	int wordStarted = 0;
	int startIndex = 0;
	int endIndex = 0;
	while (*temp != '\0'){
		
		if (!wordStarted && isWordChar(*temp)){
			wordStarted = 1;
			startIndex = iter;
		}
		else if (wordStarted && !isWordChar(*temp)) {
			wordStarted = 0;
			endIndex = iter;

			words[wordIndex++] = strsubstr(temp - iter, startIndex, endIndex);
		}

		iter++;temp++;
	}
	if (wordIndex == 0 && arrLen > 0){
		words[wordIndex++] = strsubstr(temp - iter, startIndex, iter);
	}

	trend = findMostCommonWord(words, wordIndex);

	free(temp - iter);
	freeCharMatrix(words, arrLen);
	return trend;
}

int main() {

	char* sentence = readText();

	char* trend = findTrend(sentence);

	printf("the trend is --> %s", trend);
	return 0;
}