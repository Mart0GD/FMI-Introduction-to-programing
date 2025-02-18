#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#define ALPHA_SIZE 26

/*
7. Нека alpha е редица от 26 знака. Да се дефинира кодираща функция
char* encode(char* source, const char* alpha)
която заменя всяка малка латинска буква в символния низ source със съответния символ от символния низ alpha. Съответствието е следното: 'a' − alpha[0], 'b' − alpha[1], … , 'y' − alpha[24], 'z' − alpha[25]. Останалите символи не се променят.
Ако кодирането е еднозначно, да се дефинира и следната функция за декодиране:
char* decode(char* source, const char* alpha)
която получава кодиран от горната функция низ и същата таблица за съответствие.
Помислете кога кодирането е еднозначно. Напишете функция, която проверява за това.
*/

int isOneToOne(const char alpha[], size_t size) {
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if (alpha[i] == alpha[j]) return 0;
		}
	}

	return 1;
}

int getAlphaIndex(const char chr, const char* alpha, size_t size) {
	for (int i = 0; i < size; i++){
		if (chr == alpha[i]) return i;
	}

	return -1;
}

char* encode(char* source, const char alpha[]) {
	char* encoded = (char*)malloc(strlen(source) * 2 + 1);
	if (!encoded) return encoded;

	size_t index = 0;
	int iter = 0;
	while (*source){
		if (*source >= 'a' && *source <= 'z') {
			index = *source - 'a';
			encoded[iter++] = alpha[index];
		}
		else encoded[iter++] = *source;
		source++;
	}
	
	char* temp = (char*)realloc(encoded, iter + 1);
	if (!temp) return NULL;
	encoded = temp;
	encoded[iter] = '\0';

	return encoded;
}

char* decode(char* source, const char alpha[]) {
	char* decoded = (char*)malloc(strlen(source));
	if (!decoded) return NULL;

	int index = 0;
	size_t iter = 0;
	while (*source){
		index = getAlphaIndex(*source, alpha, ALPHA_SIZE);
		if (index != -1) {
			decoded[iter++] = 'a' + index;
		}
		else {
			decoded[iter++] = *source;
		}
		source++;
	}
	
	char* temp = (char*)realloc(decoded, iter + 1);
	if (!temp) return decoded;
	decoded = temp;
	decoded[iter] = '\0';

	return decoded;
}

int main_08_07() {
	char alpha[ALPHA_SIZE] = "q@z#w$s[%ed^cr&fv*tb-yh+nu";

	char* text = readText();

	char* encoded = encode(text, alpha);
	printf("encoded --> %s\n", encoded);

	int oneТoОneМapping = isOneToOne(alpha, ALPHA_SIZE);

	if (oneТoОneМapping) {
		char* decoded = decode(encoded, alpha);
		printf("decoded --> %s", decoded);
		free(decoded);
	}
	else printf("not one to one mapped!");
	
	free(text);
	free(encoded);
	
	return 0;
}