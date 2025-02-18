#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "helper.h"

#define LETTERS_SIZE 128

dinit(char** matrix, int size) {
	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
}

void swapElements(char** l1, char** l2) {
	char* temp = *l1;
	*l1 = *l2;
	*l2 = temp;
}

void permutate_All(char** words, int index, int len) {

	if (index == len) {
		for (int i = 0; i < len; i++){
			printf("%s ", words[i]);
		}
		puts(" ");
		return;
	}

	for (int i = index; i < len; i++){
		swapElements(&words[index], &words[i]);
		permutate_All(words, index + 1, len);
		swapElements(&words[index], &words[i]);
	}
}

void printAllPermutations(char** words, int rows) {
	permutate_All(words, 0, rows);
}

int main_Permutations() {

	char** words = (char**)malloc(sizeof(char*) * 3);
	if (!words) return -1;

	for (int i = 0; i < 3; i++){
		words[i] = (char*)malloc(LETTERS_SIZE);
		if (!words) {
			return -1;
		}
	}

	char* word = readText();
	int iter = 0;
	while (strlen(word) > 0){
		words[iter++] = word;
		word = readText();
	}

	printAllPermutations(words, 3);
	dinit(words, 3);
}