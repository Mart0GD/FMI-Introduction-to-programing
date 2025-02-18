#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable: 4996)

#define MAX_LETTERS 124
/*
Във времената на изкуствения интелект и автоматичното генериране на текстове е много важно да се разработят и системи, които да могат автоматично да превеждат текстове. Вашата задача днес е да направите проста преводаческа програма.

Разбира се, да преведем от истинския ни речник, за простота ще приемем, че речникът превежда една дума към дума или множество, ако разделяме с интервал или тире. Думите са максимални по възможност, непрекъснати последователности от малки и главни латински букви. При въвеждане на дума се разчита независимо дали са записани с главни или малки букви, но при превод думите ще бъдат изведени в първоначалната форма, когато съпадението на думата в текста спрямо тази в речника е пълно (т.е. с главни и малки букви).

Първата част от вашата задача е да изградите от потребителя речник и да подготвите лексикографски. За целта напишете функция, която ще позволява на потребителя брой на думите в речника, след което той толкова на брой двойки - дума и превод. След всяка двойка се извежда на екрана при трекущото състояние на речника.

Втората част е превеждането на текст. Напишете функция, която получава като аргумент речник и символен низ представляващ дължината, който може да съдържа произволни символи, и връща преведения текст. Когато думата съществува в речника се извежда нейният превод. Ако има множество преводи, те се разделят с интервал или тире, а когато няма превод, думата се извежда в първоначалния си вид. Всички останали символи като пунктуация и цифри остават непроменени.

Демонстрирайте как работят и двете функции в програма, която въвежда речник и след това въвежда многоредов текст с произволна голяма дължина до празен ред. Това се подава докато не свърши текст, който не съдържа нови символи на нов ред.

*/

char* readText() {
	int buffer = 1024;
	char* text = (char*)malloc(buffer);
	if (!text) return NULL;

	int symb = 0;
	int iter = 0;
	while ((symb = getc(stdin)) != EOF && symb != '\n'){
		if (iter < buffer) text[iter++] = symb;
		else {
			char* temp = (char*)realloc(text, buffer * 2);
			if (!temp) {
				printf("no memory to allocate text!");
				return NULL;
			}
			text = temp;
			buffer *= 2;
			text[iter++] = symb;
		}
	}
	text[iter] = '\0';

	char* temp = (char*)realloc(text, iter + 1);
	if (!temp) return text;
	text = temp;
	text[iter] = '\0';

	return text;
}

void reallocate(char** text, int* buffer) {
	char* temp = (char*)realloc(*text, *buffer * 2);
	if (!temp) return *text;
	*text = temp;
	*buffer *= 2;
}

int strcmpNS(char* str1, char* str2) {
	if (!str1 || !str2) {
		puts("error!");
		exit(-1);
	}
	const int diff = 'a' - 'A';

	char toLower1 = ' ';
	char toLower2 = ' ';
	while (*str1 && *str2){

		toLower1 = *str1 >= 'A' && *str1 <= 'Z' ? *str1 + diff : *str1;
		toLower2 = *str2 >= 'A' && *str2 <= 'Z' ? *str2 + diff : *str2;
		if (toLower1 != toLower2) break;

		str1++;str2++;
	}

	toLower1 = *str1 >= 'A' && *str1 <= 'Z' ? *str1 + diff : *str1;
	toLower2 = *str2 >= 'A' && *str2 <= 'Z' ? *str2 + diff : *str2;

	return toLower1 - toLower2;
}

int isLetter(const char chr) {
	return
		(chr >= 'a' && chr <= 'z') ||
		(chr >= 'A' && chr <= 'Z');
}

void freeMatrix(char** matrix, size_t size) {

	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
}

void printDictionary(const char** dictionary, int size) {
	for (int i = 0; i <= size - 1; i+= 2){
		printf("-- %s --> %s\n", dictionary[i], dictionary[i + 1]);
	}
}

char** createMatrix(size_t rows, size_t cols) {
	char** matrix = (char**)malloc(sizeof(char*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc(cols);
		if (!matrix[i]) {
			freeMatrix(matrix, i);
			return NULL;
		}
	}

	return matrix;
}

char** createDictionary(int size) {
	char** dictionary = createMatrix(size, MAX_LETTERS);
	if (!dictionary) return NULL;

	for (int y = 0; y < size - 1; y += 2){
		printf("Insert word --> ");
		dictionary[y] = readText();

		printf("Insert translation --> ");
		dictionary[y + 1] = readText();

		printDictionary(dictionary, y + 1);
		puts(" ");
	}

	return dictionary;
}

char* getTranslations(const char** dictionary, char* str, size_t dictionarySize) {
	int buffer = MAX_LETTERS;
	char* translations = (char*)malloc(buffer);

	int count = 0;
	int iter = 0;
	for (int i = 0; i < dictionarySize - 1; i+= 2){
		if (strcmpNS(str, dictionary[i]) == 0){
			if (count > 0) translations[iter++] = '-';

			if (iter + strlen(dictionary[i + 1]) > buffer) reallocate(&translations, &buffer);

			strcpy(translations + iter, dictionary[i + 1]);
			iter += strlen(dictionary[i + 1]);
			count++;
		}
	}

	if (count == 0) return str;


	char* temp = (char*)realloc(translations, iter + 1);
	if (!temp) return translations;
	translations = temp;
	translations[iter] = '\0';

	return translations;
}

char* getWord(char** str) {
	char* text = (char*)malloc(strlen(*str));
	if (!text) return NULL;

	int iter = 0;
	while (*(*str) && isLetter(*(*str))){
		text[iter++] = *(*str);
		(*str)++;
	}
	text[iter] = '\0';

	char* temp = (char*)realloc(text, iter + 1);
	if (!temp) return text;
	text = temp;
	text[iter] = '\0';

	return text;
}

char* translate(const char** dictionary, char* sentence, size_t dictionarySize) {
	int buffer = strlen(sentence);
	char* translatedText = (char*)malloc(buffer);
	if (!translatedText) return NULL;

	int iter = 0;
	char* currentWord = NULL;
	char* translation = NULL;
	while (*sentence) {
		if (!isLetter(*sentence)) translatedText[iter++] = *sentence;
		else {
			currentWord = getWord(&sentence);
			translation = getTranslations(dictionary, currentWord, dictionarySize);

			if (iter + strlen(translation) >= buffer) reallocate(&translatedText, &buffer);

			strcpy(translatedText + iter, translation);
			iter += strlen(translation);

			if (currentWord == translation) {
				free(currentWord);
				continue;
			}
			free(currentWord);
			free(translation);
			continue;
		}

		if (iter + 1 >= buffer) reallocate(&translatedText, &buffer);
		sentence++;
	}
	translatedText[iter] = '\0';

	char* temp = (char*)realloc(translatedText, iter + 1);
	if (!temp) return translatedText;
	translatedText = temp;
	translatedText[iter] = '\0';

	return translatedText;
}

int main_E_2() {

	int dictionarySize;
	printf("Insert dictionary size --> ");
	scanf("%d", &dictionarySize);
	getchar();

	dictionarySize *= 2;
	char** dictionary = createDictionary(dictionarySize);

	printf("text to translate --> ");
	char* text = NULL;
	char* temp; 
	while ((text = readText()) && strlen(text) > 0) {
		printf("Text --> %s\n", text);

		temp = translate(dictionary, text, dictionarySize);
		printf("Translated --> %s\n", temp);

		free(temp);
		free(text);
	}
	if (text) free(text);

	
	freeMatrix(dictionary, dictionarySize);
	return 0;
}