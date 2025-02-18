#include "helper.h"

/*
������ 2: �� �� ������ ���������� ������� atoiRec().
����: "112", �����: 112
*/

int atoiRecTail(char* str, int num) {
	if (*(str + 1) == '\0') return (num * 10) + (*str - '0');


	return atoiRecTail(str + 1, (num * 10) + (*str - '0'));
	
}

int atoiRec(char* str) {
	return atoiRecTail(str, 0);
}

int main_S_02() {

	char* str = readText();
	int num = atoiRec(str);

	printf("%d", num);
	return 0;
}