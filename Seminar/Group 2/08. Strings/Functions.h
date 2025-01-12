#include<stdio.h>
#include<stdlib.h>

// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function declarations
static char* readText() {
	unsigned capacity = 1024;
	int symb;
	int size = 0;

	char* text = (char*)malloc(sizeof(char) * capacity);
	if (!text) return NULL;

	while ((symb = getc(stdin)) != EOF && symb != '\n') {
		if (size < capacity) {
			text[size++] = symb;
			continue;
		}

		capacity *= 2;
		char* newText = (char*)realloc(text, sizeof(char) * (capacity));
		if (!newText) {
			free(text);
			return NULL;
		}
		text = newText;
	}
	text[size] = '\0';

	return text;
}

static char* copyValues(const char* fromArr) {
	int len = strlen(fromArr);
	char* newArr = (char*)malloc(sizeof(char) * (len + 1));
	if (!newArr)
		return newArr;

	int iter = 0;
	while (*fromArr != '\0') {
		newArr[iter++] = *(fromArr++);
	}
	newArr[iter] = '\0';

	return newArr;
}

static unsigned strlen(const char* str) {
	unsigned len = 0;
	while (*str != '\0') {
		len++; str++;
	}

	return len;
}

static char* strcpy(const char* str, const unsigned len) {
	char* wordCopy = (char*)malloc(sizeof(char) * (len + 1));
	if (!wordCopy) return NULL;

	for (int i = 0; i < len; i++){
		wordCopy[i] = str[i];
	}
	wordCopy[len] = '\0';

	return wordCopy;
}

static char* strcnc(const char* str1, const char* str2) {
	const unsigned newLen = strlen(str1) + strlen(str2);

	char* cntChar = (char*)malloc(sizeof(char) * newLen);

	int index = 0;
	while (*str1 != '\0' && *str2 != '\0'){
		if (*str1 != 0) {
			cntChar[index++] = *(str1++);
		}
		else {
			cntChar[index++] = *(str2++);
		}
	}

	return cntChar;
}

static int strcts(const char* str, const char value) {
	while (*str != '\0')
		if (*(str++) == value) return 1;
	return 0;
}

static char* strsubstr(const char* str, const unsigned startIndex, const unsigned endIndex) {
	if (endIndex > strlen(str) || startIndex < 0) return NULL;

	char* substr = (char*)malloc(sizeof(char) * ((endIndex - startIndex) + 1));
	int index = 0;
	for (int i = startIndex; i < endIndex; i++){
		substr[index++] = str[i];
	}
	substr[index] = '\0';

	return substr;
}

static int equals(const char* word1, const char* word2) {
	int word1Len = strlen(word1);
	int word2Len = strlen(word2);

	if (word1Len != word2Len) return 0;

	while (*word1 != '\0')
		if (*(word1++) != *(word2++)) return 0;

	return 1;
}
#endif