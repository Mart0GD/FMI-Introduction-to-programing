#include<stdio.h>
#include<stdlib.h>


#pragma once

#ifndef MYHEADER_H  
#define MYHEADER_H

static char* readText() {
	int buffer = 1024;

	char* text = (char*)malloc(buffer);
	if (!text) return text;

	int symb = 0;
	int iter = 0;
	while ((symb = getc(stdin)) != EOF && symb != '\n'){
		if (iter < buffer) text[iter++] = symb;
		else {
			char* temp = (char*)realloc(text, buffer * 2);
			if (!temp) return text;
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

#endif