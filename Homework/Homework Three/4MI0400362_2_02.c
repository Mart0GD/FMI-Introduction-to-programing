//#include<stdio.h>
//#include<stdlib.h>
//#include "Functions.h"
//
//#pragma warning(push)
//#pragma warning(disable: 4996)
//
//#define WORDS_BUFFER 64
//#define MEMORY_MESSAGE "No available memory to allocate"
//
//void freeCharMatrix(char** matrix, const unsigned size) {
//	for (int i = 0; i < size; i++)
//		free(matrix[i]);
//	free(matrix);
//}
//
//char** createCharMatrix(const unsigned rows) {
//
//	char** matrix = (char**)malloc(sizeof(char*) * rows);
//	if (!matrix) {
//		puts(MEMORY_MESSAGE);
//		exit(EXIT_FAILURE);
//	}
//
//	for (int i = 0; i < rows; i++) {
//		matrix[i] = (char*)malloc(sizeof(char) * WORDS_BUFFER);
//		if (!matrix[i]) {
//			puts(MEMORY_MESSAGE);
//			freeCharMatrix(matrix, i);
//			exit(EXIT_FAILURE);
//		}
//	}
//
//	return matrix;
//}
//
//char** copyMatrix(const char** matrix, const unsigned size) {
//	char** copy = createCharMatrix(size);
//
//	for (int i = 0; i < size; i++){
//		copy[i] = substr(matrix[i], 0, WORDS_BUFFER);
//	}
//
//	return copy;
//}
//
//void printWords(char** matrix, int size) {
//	for (int i = 0; i < size; i++){
//		printf("%s ", matrix[i]);
//	}
//}
//
//char* toLower(const char* str) {
//	const unsigned distance = 'a' - 'A';
//	int len = strlen(str);
//
//	int iter = 0;
//	char* lower = (char*)malloc(sizeof(char) * (len + 1));
//	while (*str != '\0') {
//		if (isUpperWordChar(*str)) { lower[iter] = (*str) + distance; }
//		else { lower[iter] = *str; }
//
//		str++;iter++;
//	}
//	lower[iter] = '\0';
//
//	return lower;
//}
//
//int isUpperWordChar(const char chr) {
//	return chr >= 'A' && chr <= 'Z';
//}
//
//int IsDigit(const char chr) {
//	return
//		chr >= 'a' && chr <= 'z' ||
//		chr >= '0' && chr <= '9' ||
//		chr == '-';
//}
//
//int isNumber(const char chr) {
//	return chr >= '0' && chr <= '9';
//}
//
//char** split(const char* str, int* count) {
//	char** words = createCharMatrix(strlen(str), WORDS_BUFFER);
//
//	int iter = 0;
//	int startIndex = 0;
//	int endIndex = 0;
//	int wordStarted = 0;
//	while (*str != '\0'){
//		if (!wordStarted && IsDigit(*str)){
//			wordStarted = 1;
//			startIndex = iter;
//		}
//		else if (wordStarted && !IsDigit(*str)) {
//			wordStarted = 0;
//			endIndex = iter;
//
//			words[(*count)++] = substr(str - iter, startIndex, endIndex);
//		}
//
//		iter++;str++;
//	}
//	if (wordStarted){ // one word sentence or no spaces or other splitter chars
//		words[(*count)++] = substr(str - iter, startIndex, iter);
//	}
//
//	words = (char**)realloc(words, sizeof(char*) * iter);
//	if (!words){
//		puts(MEMORY_MESSAGE);
//		exit(EXIT_FAILURE);
//	}
//
//	return words;
//}
//
//int isSeen(const char* word, const char** uniqueWords, const unsigned count) {
//	for (int i = 0; i < count; i++)
//		if (strcmp(word, uniqueWords[i]) == 0) return 1;
//
//	return 0;
//}
//
//char** getUniqueWords(const char** words, unsigned* wordsCount, unsigned const allWordsCount) {
//	char** uniqueWords = createCharMatrix(sizeof(char) * allWordsCount);
//
//	for (int i = 0; i < allWordsCount; i++){
//		if (!isSeen(words[i], uniqueWords, *wordsCount)){
//			uniqueWords[(*wordsCount)++] = substr(words[i], 0, WORDS_BUFFER);
//		}
//	}
//
//	uniqueWords = (char**)realloc(uniqueWords ,sizeof(char*) * (*wordsCount));
//	if (!uniqueWords) {
//		puts(MEMORY_MESSAGE);
//		exit(EXIT_FAILURE);
//	}
//	return uniqueWords;
//}
//
//int* getWordOccurances(const char** uniqueWords, const char** allWords, const unsigned allWordsCount, const unsigned uniqueWordsCount) {
//
//	int* wordOccurances = (int*)calloc(uniqueWordsCount, sizeof(int));
//	if (!wordOccurances) {
//		puts(MEMORY_MESSAGE);
//		exit(EXIT_FAILURE);
//	}
//
//	for (int i = 0; i < allWordsCount; i++){
//		for (int j = 0; j < uniqueWordsCount; j++){
//			if (strcmp(uniqueWords[j], allWords[i]) == 0){
//				wordOccurances[j]++;
//				break;
//			}
//		}
//	}
//
//	return wordOccurances;
//}
//
//void sortWords(char** uniqueWords, int* wordsOccurances, const unsigned uniqueWordsCount) {
//
//	int swapped = 0;
//	int temp = 0;
//	char* temp2 = NULL;
//	for (int i = 0; i < uniqueWordsCount - 1; i++){
//		swapped = 0;
//		for (int j = 0; j < uniqueWordsCount - i - 1; j++){
//			if (wordsOccurances[j] > wordsOccurances[j + 1]) continue;
//			else if (wordsOccurances[j] == wordsOccurances[j + 1] && strcmp(uniqueWords[j], uniqueWords[j + 1]) < 0) continue;
//
//			temp = wordsOccurances[j];
//			wordsOccurances[j] = wordsOccurances[j + 1];
//			wordsOccurances[j + 1] = temp;
//
//			temp2 = uniqueWords[j];
//			uniqueWords[j] = uniqueWords[j + 1];
//			uniqueWords[j + 1] = temp2;
//
//			swapped = 1;
//		}
//		if (!swapped) break;
//	}
//}
//
//int replace(char** text, const unsigned whatStartIndex, const unsigned whatEndIndex, const char* with) {
//	int textLen = strlen(*text);
//	int whatLen = whatEndIndex - whatStartIndex;
//	int withLen = strlen(with);
//
//	int diff = whatLen - withLen < 0 ? -(whatLen - withLen) : whatLen - withLen;
//	if (whatLen > withLen){
//		int newLen = textLen - diff;
//
//		for (int i = whatStartIndex + withLen; i < textLen; i++){
//			(*text)[i] = (*text)[i + diff];
//		}
//
//		*text = (char*)realloc(*text ,sizeof(char) * (newLen + 1));
//		if (!(*text)) {
//			puts(MEMORY_MESSAGE);
//			exit(EXIT_FAILURE);
//		}
//		(*text)[newLen] = '\0';
//
//		int iter = whatStartIndex;
//		while (iter < whatStartIndex + withLen){
//			(*text)[iter++] = *(with++);
//		}
//		return -diff;
//	}
//	else if (whatLen < withLen) {
//		int newLen = textLen + diff;
//
//		*text = (char*)realloc(*text, sizeof(char) * (newLen + 1));
//		if (!(*text)) {
//			puts(MEMORY_MESSAGE);
//			exit(EXIT_FAILURE);
//		}
//
//		for (int i = newLen; i > whatStartIndex; i--){
//			(*text)[i] = (*text)[i - diff];
//		}
//		(*text)[newLen] = '\0';
//
//		int iter = whatStartIndex;
//		while (iter < whatStartIndex + withLen) {
//			(*text)[iter++] = *(with++);
//		}
//		return diff;
//	}
//	else {
//		int iter = whatStartIndex;
//		while (iter < whatStartIndex + withLen){
//			(*text)[iter++] = *(with++);
//		}
//	}
//
//	return 0;
//}
//
//char* createCompressedString(const char* text, const char** wordsList, const unsigned uniqueWordsCount) {
//	char* compressed = substr(text, 0, strlen(text));
//	if (!compressed) {
//		puts(MEMORY_MESSAGE);
//		exit(EXIT_FAILURE);
//	}
//
//	int startIndex = 0;
//	int endIndex = 0;
//	int wordStarted = 0;
//	int iter = 0;
//
//	char* what = NULL;
//	char* with = NULL;
//	while (compressed[iter] != '\0'){
//
//		if (!wordStarted && IsDigit(compressed[iter])) {
//			startIndex = iter;
//			wordStarted = 1;
//		}
//		else if (wordStarted && !IsDigit(compressed[iter])) {
//			endIndex = iter;
//			wordStarted = 0;
//
//			what = substr(compressed, startIndex, endIndex);
//			for (int i = 0; i < uniqueWordsCount; i++){
//				if (strcmp(what, wordsList[i]) == 0) {
//					with = toString(i);
//					break;
//				}
//			}
//
//			iter += replace(&compressed, startIndex, endIndex, with);
//		}
//
//		iter++;
//	}
//	if (wordStarted)
//	{
//		what = substr(compressed, startIndex, iter);
//		for (int i = 0; i < uniqueWordsCount; i++) {
//			if (strcmp(what, wordsList[i]) == 0) {
//				with = toString(i);
//				break;
//			}
//		}
//
//		iter += replace(&compressed, startIndex, iter, with);
//	}
//	compressed[iter] = '\0';
//
//	return compressed;
//}
//
//char* createDecompressedString(const char* compressedStr, const char** wordsList, const unsigned wordsListLength) {
//	char* decompressed = substr(compressedStr, 0, strlen(compressedStr));
//	
//	int startIndex = 0;
//	int endIndex = 0;
//	int numberStarted = 0;
//	int iter = 0;
//
//	int what = 0;
//	char* with = NULL;
//	while (decompressed[iter] != '\0') {
//
//		if (!numberStarted && isNumber(decompressed[iter])) {
//			startIndex = iter;
//			numberStarted = 1;
//		}
//		else if (numberStarted && !isNumber(decompressed[iter])) {
//			endIndex = iter;
//			numberStarted = 0;
//
//			what = posAtoi(substr(decompressed, startIndex, endIndex));
//			for (int i = 0; i < wordsListLength; i++) {
//				if (what == i) {
//					with = wordsList[i];
//					break;
//				}
//			}
//
//			iter += replace(&decompressed, startIndex, endIndex, with);
//		}
//
//		iter++;
//	}
//	if (numberStarted)
//	{
//		what = posAtoi(substr(decompressed, startIndex, iter));
//		for (int i = 0; i < wordsListLength; i++) {
//			if (what == i) {
//				with = wordsList[i];
//				break;
//			}
//		}
//
//		iter += replace(&decompressed, startIndex, iter, with);
//	}
//	decompressed[iter] = '\0';
//
//	return decompressed;
//}
//
//char* compress(const char* str, char*** wordsList, unsigned* wordsListLength, unsigned* wordsCount) {
//	char* lowered = toLower(str);
//
//	int allWordsCount = 0;
//	char** words = split(lowered, &allWordsCount);
//
//	int uniqueWordsCount = 0;
//	char** uniqueWords = getUniqueWords(words, &uniqueWordsCount, allWordsCount);
//	int* wordsOccurances = getWordOccurances(uniqueWords, words, allWordsCount, uniqueWordsCount);
//
//	sortWords(uniqueWords, wordsOccurances, uniqueWordsCount);
//
//	char* compressedString = createCompressedString(lowered, uniqueWords, uniqueWordsCount);
//
//	*wordsList = copyMatrix(uniqueWords, uniqueWordsCount);
//	*wordsListLength = uniqueWordsCount;
//	*wordsCount = allWordsCount;
//
//	free(lowered);
//	freeCharMatrix(uniqueWords, uniqueWordsCount);
//	freeCharMatrix(words, allWordsCount);
//	free(wordsOccurances);
//	return compressedString;
//}
//
//int main() {
//
//	char* str = readText();
//
//	unsigned wordsListLength = 0;
//	unsigned wordsCount = 0;
//
//	char** wordsList = createCharMatrix(strlen(str), WORDS_BUFFER);
//	char* compressedStr = compress(str, &wordsList, &wordsListLength, &wordsCount);
//	printf("%s", compressedStr);
//
//	puts("\nWords: ");
//	printWords(wordsList, wordsListLength);
//	puts(" ");
//
//	puts("Decompressed text:");
//	char* decompressed = createDecompressedString(compressedStr, wordsList, wordsListLength);
//	printf("%s\n", decompressed);
//
//	printf("Are both text equal --> %d", strcmp(str, decompressed));
//
//	free(str);
//	freeCharMatrix(wordsList, wordsListLength);
//	free(decompressed);
//	free(compressedStr);
//	return 0;
//}