#include<stdio.h>
#include "helpers.h"
#include<stdlib.h>

#pragma warning(disable: 4996)
/*
Напишете програма, която намира най-дългия под-низ в даден низ, който се среща повече от един път
*/

char* strsubstr(const char* text, size_t start, size_t end) {
	if (!text || start > end) {
		return NULL;
	}

	char* substr = (char*)malloc(end - start + 1);
	if (!substr) return NULL;

	int iter = 0;
	for (size_t i = start; i < end; i++) {
		substr[iter++] = text[i];
	}
	substr[iter] = '\0';

	return substr;
}

void deinit(char** matrix, size_t size) {
	for (size_t i = 0; i < size; i++){
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
}

void sort(char** substrings, size_t count) {

	int swapped = 0;
	char* temp = NULL;
	for (int i = 0; i < count; i++){
		for (int j = 0; j < count - i - 1; j++){
			if (!substrings[j] || !substrings[j + 1]) continue;
			if (strlen(substrings[j]) > strlen(substrings[j + 1]) ||
				(strlen(substrings[j]) == strlen(substrings[j + 1]) && (strcmp(substrings[j], substrings[j + 1]) > 0))) continue;

			temp = substrings[j];
			substrings[j] = substrings[j + 1];
			substrings[j + 1] = temp;
			swapped = 1;
		}
		if (!swapped) break;
	}
}

char* findLongestReacurringSubstring(char* text) {
	size_t textLen = strlen(text);
	size_t substringsCount = (textLen * (textLen + 1)) / 2;

	char** substrings = (char**)malloc(sizeof(char*) * substringsCount);
	if (!substrings) return NULL;

	for (size_t i = 0; i < substringsCount; i++) {
		substrings[i] = (char*)malloc(textLen + 1);
		if (!substrings[i]) {
			deinit(substrings, i);
			return NULL;
		}
	}

	char* currentSubstring = NULL;
	int count = 0;
	for (int i = 0; i < textLen; i++){
		for (int j = i; j < textLen; j++){
			currentSubstring = strsubstr(text, i, j + 1);
			substrings[count++] = currentSubstring;
		}
	}

	sort(substrings, substringsCount);
	char* chosen = NULL;
	for (size_t i = 0; i < substringsCount - 1; i++){
		if (strcmp(substrings[i], substrings[i + 1]) == 0) {
			chosen = strsubstr(substrings[i], 0, strlen(substrings[i]));
			deinit(substrings, substringsCount);

			return chosen;
		}
	}

	printf("No reacurring substring found returning word --> ");
	chosen = strsubstr(substrings[0], 0, strlen(substrings[0]));
	deinit(substrings, substringsCount);
	return chosen;
}

int main_08_14() {

	char* text = readText();

	char* longestReaccuringSubstring = findLongestReacurringSubstring(text);
	printf(longestReaccuringSubstring);

	free(text);
	free(longestReaccuringSubstring);
	return 0;
}