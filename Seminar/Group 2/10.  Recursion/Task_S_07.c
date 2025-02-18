#include "helper.h"

/*
Çàäà÷à 7: Äà ñå íàïèøå ğåêóğñèâíà ôóíêöèÿ, êîÿòî âğúùà ïúğâàòà ãëàâíà áóêâà â íèç.
Âõîä: abcMdGREm, Èçõîä: M
*/

char getFirstUpperLetter(char* str) {
	if (*str == '\0') return ' ';
	else if (*str >= 'A' && *str <= 'Z') return *str;

	return getFirstUpperLetter(str + 1);
}

int main_S_07() {

	char* str = readText();

	char firstUpperLetter = getFirstUpperLetter(str);
	printf("%c", firstUpperLetter);
	return 0;
}