//#include<stdio.h>
//#include<stdlib.h>
//#include "helpers.h"
//
///*. Да се напише функция, която проверява дали символен низ съдържа правилно записано реално число според правилата на литералите в C.*/
///*
//Десетично число	3.14					3.14
//Цяло число със запетая	5.				5.0
//Число, започващо с .	.5				0.5
//Научна нотация	1.23e3					1230.0
//Отрицателно с експонента-4.5E-2			-0.045
//Съкратена експонента	2e10			20000000000.0
//float число	3.14f						3.14 като float
//long double число	2.71L				2.71 като long double
//*/
//
//
//int isRealNumber(char* number) {
//	if (!number) {
//		printf("null pointer!");
//	}
//	
//	char firstDigit = *number; 
//	char lastDigit = number[strlen(number) - 1];
//
//	int hasSign = *number == '+' || *number == '-' ? (1, number++) : 0;
//	int hasDot = 0;
//	int hasExponent = 0;
//	int hasModifier = lastDigit == 'f' || lastDigit == 'F' || lastDigit == 'L' || lastDigit == 'l';
//
//	while (*number){
//		if(*number >= '0' && *number <= 9){
//
//		if (*number == '.') hasDot == 1;
//		if (*number == 'e' || number == 'E') {
//			hasExponent = 1;
//	}
//}
//
//int main() {
//	char* number = readText();
//
//	int isValidRealNumber = isRealNumber();
//	return 0;
//}