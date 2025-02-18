#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

/*
Задача 14. Професор Х се забавлява като съставя интересни числови редици. Последното му творчество е следната редица:
1, 121, 1213121, 121312141213121, …
Първият член на редицата е 1. Всеки от следващите членове се получава от две копия на предходния член на редицата, между които е изписан поредният номер на текущия член. Тъй като дължината на числата в редицата нараства много бързо и ръчното им изписване е доста трудоемко, професорът се нуждае от програма, която да извежда посочения от него член на тази редица. Помогнете му като напишете програма, която по въведено цяло положително число n < 20 извежда n-тия член на редицата, следван от знак за нов ред.
Пример:
Вход 5
Изход
1213121412131215121312141213121
*/

char* toString(int index) {
	int digits = 1;
	int temp = index;
	while (temp / 10) digits++;

	char* str = (char*)malloc(digits + 1);
	if (!str) return NULL;

	for (int i = digits - 1; i >= 0; i--){
		str[i] = (index % 10) + '0';
		index /= 10;
	}
	str[digits] = '\0';

	return str;
}

char* calculateMember(int n, char* str, int index) {
	if (index == n) {
		return str;
	}
	
	char* end = (char*)malloc(strlen(str) + 1);
	if (!end) return NULL;
	strcpy(end, str);

	char* mid = toString(index + 1);
	if (!mid) return NULL;
	
	strcpy(str + strlen(str), mid);
	strcpy(str + strlen(str), end);

	free(mid);
	free(end);
	calculateMember(n, str, index + 1);
}

char* getNthMemeber(int n) {
	if (n == 1) return toString(1);

	int size = 1;
	for (int i = 2; i <= n; i++){
		size = size + 1 + size;
	}

	char* str = (char*)malloc(size + 1);
	if (!str) return NULL;
	str[0] = '1';
	str[1] = '\0';

	return calculateMember(n, str, 1);
}

int main_09_14() {

	int n = 0;
	scanf("%d", &n);

	char* nThMember = getNthMemeber(n);
	printf("%s", nThMember);
	return 0;
}