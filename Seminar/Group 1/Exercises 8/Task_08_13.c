#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#define MIN_SEQUENCE_LENGTH 4
#define MAX_SEQUENCE_SIZE 1024

#pragma warning(disable: 4996)
/*
Реализирайте следната функция: 
char* rleEncode(const char* text); 
която компресира текст, съставен от малки латински букви, посредством RLE алгоритъм и връща  получения резултат в динамично заделен низ с точната големина. Демонстрирайте използването на  функцията в примерна програма. 
RLE е компресия, при която еднаквите символи се заменят с число и съответния символ в скоби. За да  има смисъл се заменят поне четири последователни еднакви символа. 
Пример: 
Вход: аbcdddddaaaaaaabccadddd 
Изход: abc(5d)(7a)bcca(4d) 
*/

/*
Напишете и съответната функция за декомпресиране:
char* rleDecode(const char* rleString);
Пример:
Вход: abc(5d)(7a)bcca(4d)
Изход: аbcdddddaaaaaaabccadddd
*/

char* toString(int number) {
	int pow = 1;
	int temp = number;
	while (temp /= 10)
		pow++;

	char* str = (char*)malloc(pow + 1);
	if (!str) return NULL;

	for (int i = pow - 1; i >= 0; i--){
		str[i] = (number % 10) + '0';
		number /= 10;
	}
	str[pow] = '\0';

	return str;
}

char* buildCompressed(const char chr, size_t count) {
	char* number = toString(count);
	size_t len = strlen(number);

	char* compressed = (char*)malloc((3 + len) + 1);
	char* start = compressed;

	*(compressed++) = '(';
	strncpy(compressed, number, len);
	compressed += len;
	*(compressed++) = chr;
	*(compressed++) = ')';
	*compressed = '\0';

	free(number);
	return start;
}

char* rleEncode(char* text) {
	char* encoded = (char*)malloc(strlen(text));
	if (!encoded) return encoded;

	char currentLetter = *text;
	int count = 1;
	int iter = 0;
	char* temp = NULL;
	while (*text){
		currentLetter = *text;

		if (currentLetter == *(text + 1)) {
			count++; text++;
			continue;
		}

		if (count >= 4) {
			temp = buildCompressed(currentLetter, count);
			if (!temp) {
				printf("error!");
				continue;
			}

			strncpy(encoded + iter, temp, strlen(temp));
			iter += strlen(temp);
			free(temp);
		}
		else {
			for (int i = 0; i < count; i++)
				encoded[iter++] = currentLetter;
		}

		text++;count = 1;
	}
	encoded[iter] = '\0';

	return encoded;
}

char* rleDecode(const char* rleString) {
	char* decoded = (char*)malloc(MAX_SEQUENCE_SIZE);
	if (!decoded) return NULL;

	int iter = 0;
	size_t count = 0;
	while (*rleString){
		if (*rleString != '(') decoded[iter++] = *rleString;
		else {
			rleString++;
			while (*rleString < 'a' || *rleString > 'z'){
				count *= 10;
				count += *rleString - '0';
				rleString++;
			}

			for (int i = 0; i < count; i++){
				decoded[iter++] = *rleString;
			}

			rleString++;count = 0;
		}
		rleString++; 
	}
	
	char* temp = (char*)realloc(decoded, iter + 1);
	if (!temp) return decoded;
	decoded = temp;
	decoded[iter] = '\0';
 
	return decoded;
}

int main_08_13() {

	char* text = readText();

	char* encoded = rleEncode(text);
	printf("Encoded --> %s\n", encoded);

	char* decoded = rleDecode(encoded);
	printf("Decoded --> %s", decoded);

	free(text);
	free(encoded);
	return 0;
}