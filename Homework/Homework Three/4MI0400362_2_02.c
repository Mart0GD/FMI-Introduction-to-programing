#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_TEXT_SIZE 1024
#define LETTERS_BUFFER 64

#pragma warning(push)
#pragma warning(disable: 4996)

void reallocate(char** arr, const int newSize) {
	char* temp = (char*)realloc(*arr, sizeof(char) * (newSize + 1));
	if (!temp) {
		puts("reallocation failed!");
		return;
	}

	*arr = temp;
}

char* readText() {

	char* text = (char*)malloc(sizeof(char) * MAX_TEXT_SIZE);
	if (!text) return text;

	int symb = 0;
	int iter = 0;

	while ((symb = getc(stdin)) != EOF && symb != '\n') {
		if (iter < MAX_TEXT_SIZE) text[iter++] = symb;
		else {
			puts("Invalid input, no more than 1023 sumbols can be entered!");
			exit(-1);
		}
	}

	reallocate(&text, iter);
	text[iter] = '\0';

	return text;
}

void freeCharMatrix(char** matrix, const int size) {
	for (int i = 0; i < size; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int myStricmp(const char* str1, const char* str2) {
	if (!str1 || !str2) {
		puts("Null pointer detected!");
		return -1;
	}
	const int diff = 'a' - 'A';

	char chr1;
	char chr2;
	while (*str1 && *str2)
	{
		chr1 = *str1 >= 'A' && *str1 <= 'Z' ? *str1 + diff : *str1;
		chr2 = *str2 >= 'A' && *str2 <= 'Z' ? *str2 + diff : *str2;

		if (chr1 != chr2) break;
		str1++;str2++;
	}
	chr1 = *str1 >= 'A' && *str1 <= 'Z' ? *str1 + diff : *str1;
	chr2 = *str2 >= 'A' && *str2 <= 'Z' ? *str2 + diff : *str2;

	return (int)(chr1 - chr2);
}

int isValidChar(const char chr) {
	return
		chr >= 'A' && chr <= 'Z' ||
		chr >= 'a' && chr <= 'z' ||
		chr >= '0' && chr <= '9' ||
		chr == '-';
}

char* toString(int number) {
	int power = 0;
	int temp = number;
	while (temp /= 10)
		power++;

	char* str = (char*)malloc(sizeof(char) * (power + 1));
	if (!str) return str;

	for (int i = power; i >= 0; i--) {
		str[i] = (number % 10) + '0';
		number /= 10;
	}
	str[power + 1] = '\0';

	return str;
}

char** createCharMatrix(const int rows, const int cols) {
	char** matrix = (char**)malloc(sizeof(char*) * rows);
	if (!matrix) return matrix;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc(sizeof(char) * cols);
		if (!matrix[i]) {
			puts("No memory to allocate!");
			freeCharMatrix(matrix, i);
			exit(-1);
		}
	}

	return matrix;
}

void getNextWord(char** text) {
	while (*(*text) && !isValidChar(*(*text)))
		(*text)++;
}

char* extractWord(char** text) {
	char* word = (char*)malloc(sizeof(char) * LETTERS_BUFFER);
	if (!word) return word;

	int wordSize = 0;
	while (*(*text) && isValidChar(*(*text))) {
		if (wordSize == LETTERS_BUFFER - 1) {
			puts("Invalid word detected. Words with more than 64 sybols are not permited!");
			exit(-1);
		}

		word[wordSize++] = *(*text);
		(*text)++;
	}

	reallocate(&word, wordSize);
	word[wordSize] = '\0';

	return word;
}

int isSeen(const char** matrix, const char* word, const int matrixSize) {
	for (int i = 0; i < matrixSize; i++)
		if (myStricmp(word, matrix[i]) == 0) return 1;

	return 0;

}

char* toLower(const char* text) {
	const int diff = 'a' - 'A';

	char* toLower = (char*)malloc(sizeof(char) * (strlen(text) + 1));
	if (!toLower) return NULL;

	int index = 0;
	while (*text) {
		if (*text >= 'A' && *text <= 'Z') toLower[index++] = *text + diff;
		else toLower[index++] = *text;
		text++;
	}
	toLower[index] = '\0';

	return toLower;
}

char** getUniqueWords(const char* text, int* uniqueWordsCount) {
	char** uniqueWords = createCharMatrix(MAX_TEXT_SIZE, LETTERS_BUFFER);

	char* word = NULL;
	while ((getNextWord(&text), *text)) {
		word = extractWord(&text);

		if (!isSeen(uniqueWords, word, *uniqueWordsCount)) {
			uniqueWords[(*uniqueWordsCount)++] = toLower(word);
		}
	}

	char** temp = (char**)realloc(uniqueWords, sizeof(char*) * (*uniqueWordsCount));
	if (!temp) return uniqueWords;
	uniqueWords = temp;

	return uniqueWords;
}

char* findMatch(const char* text, const char* what) {
	char* word = NULL;
	while ((getNextWord(&text), *text)) {
		word = extractWord(&text);
		if (myStricmp(word, what) == 0) return text - strlen(word);
	}

	return NULL;
}

int* getWordsOccurances(const char* text, const char** uniqueWords, const int uniqueWordsCount) {
	int* wordsOccurances = (int*)calloc(uniqueWordsCount, sizeof(int));
	if (!wordsOccurances) return wordsOccurances;

	char* word = NULL;
	char* tempTextPtr;
	for (int i = 0; i < uniqueWordsCount; i++) {
		tempTextPtr = text;
		word = findMatch(text, uniqueWords[i]);

		while (word) {
			wordsOccurances[i]++;
			word = findMatch(word + strlen(uniqueWords[i]), uniqueWords[i]);
		}
	}

	return wordsOccurances;
}

void sortWords(char** words, int* uniqueWordsOccurances, const int uniqueWordsCount) {
	int swapped = 0;
	int temp = 0;
	char* tempPtr = NULL;

	for (int i = 0; i < uniqueWordsCount - 1; i++) {
		swapped = 0;
		for (int j = 0; j < uniqueWordsCount - 1 - i; j++) {
			if (uniqueWordsOccurances[j] > uniqueWordsOccurances[j + 1]) continue;
			else if (uniqueWordsOccurances[j] == uniqueWordsOccurances[j + 1] && myStricmp(words[j], words[j + 1]) < 0) continue;

			temp = uniqueWordsOccurances[j];
			uniqueWordsOccurances[j] = uniqueWordsOccurances[j + 1];
			uniqueWordsOccurances[j + 1] = temp;

			tempPtr = words[j];
			words[j] = words[j + 1];
			words[j + 1] = tempPtr;

			swapped = 1;
		}
		if (!swapped) break;
	}
}

char* compressText(const char* text, char*** uniqueWords, int* uniqueWordsCount) {
	*uniqueWords = getUniqueWords(text, uniqueWordsCount);

	int* uniqueWordsOccurances = getWordsOccurances(text, *uniqueWords, *uniqueWordsCount);
	sortWords(*uniqueWords, uniqueWordsOccurances, *uniqueWordsCount);

	char* compressedText = (char*)malloc(sizeof(char) * strlen(text));
	if (!compressedText) return compressedText;

	char* word = NULL;
	char* replacer = NULL;
	int len = 0;
	while (*text){
		
		if (!isValidChar(*text)) compressedText[len++] = *(text++);
		else {
			word = extractWord(&text);
			for (int i = 0; i < *uniqueWordsCount; i++){
				if (myStricmp((*uniqueWords)[i], word) == 0){
					replacer = toString(i);

					strcpy(compressedText + len, replacer);
					len += strlen(toString(i));
					break;
				}
			}
		}

	}

	reallocate(&compressedText, len);
	compressedText[len] = '\0';

	free(uniqueWordsOccurances);
	return compressedText;
}

char* decompressText(const char* text, const char** compressedWords, const int compressedWordsCount) {
	char* decompressed = (char*)malloc(sizeof(char) * MAX_TEXT_SIZE);
	if (!decompressed) return decompressed;

	int len = 0;
	int index = 0;
	while (*text) {
		if (!isValidChar(*text)) decompressed[len++] = *(text++);
		else {
			index = atoi(extractWord(&text));

			strcpy(decompressed + len, compressedWords[index]);
			len += strlen(compressedWords[index]);
		}
	}

	reallocate(&decompressed, len);
	decompressed[len] = '\0';
	return decompressed;
}

int main_02() {
	printf("Enter text: ");
	char* text = readText();

	int uniqueWordsCount = 0;
	char** uniqueWords = createCharMatrix(MAX_TEXT_SIZE, LETTERS_BUFFER);
	char* compressed = compressText(text, &uniqueWords, &uniqueWordsCount);

	printf("Compressed text --> %s\n", compressed);
	printf("Unique words list: \n");
	for (int i = 0; i < uniqueWordsCount; i++) {
		printf("%d. %s\n", i, uniqueWords[i]);
	}

	char* decompressed = decompressText(compressed, uniqueWords, uniqueWordsCount);

	printf("\ndecompressed text --> %s\n", decompressed);
	printf("\nAre input text and decompressed equal --> %s", myStricmp(text, decompressed) == 0 ? "yes" : "no");

	free(text);
	free(compressed);
	free(decompressed);
	freeCharMatrix(uniqueWords, uniqueWordsCount);
	return 0;
}