#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

/*
������ 14. �������� � �� ��������� ���� ������� ��������� ������� ������. ���������� �� ���������� � �������� ������:
1, 121, 1213121, 121312141213121, �
������� ���� �� �������� � 1. ����� �� ���������� ������� �� �������� �� ��� ����� �� ���������� ���� �� ��������, ����� ����� � ������� ��������� ����� �� ������� ����. ��� ���� ��������� �� ������� � �������� �������� ����� ����� � ������� �� ��������� � ����� ���������, ���������� �� ������ �� ��������, ����� �� ������� ��������� �� ���� ���� �� ���� ������. ��������� �� ���� �������� ��������, ����� �� �������� ���� ����������� ����� n < 20 ������� n-��� ���� �� ��������, ������� �� ���� �� ��� ���.
������:
���� 5
�����
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