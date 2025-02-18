#include<stdio.h>
#include "helper.h"

/*
������ 9: �� �� ������ ���������� �������, ����� ������ ���, ������ � ��������� ����� n � ����� ��������� �� n-���� ������� �� ������� � ����. ��� ������ ����, ��������� �� ����� -1.
����:
abcMdGREaama   a   3
�����:
9
*/


int getNPosition(const char* str, char chr, int n, int count, int index) {
	if (*str == '\0') return -1;
	else if (*str == chr) count++;

	if (count == n) return index;
	return getNPosition(str + 1, chr, n, count, index + 1);
}

int getNPositionWrapper(const char* str, char chr, int n) {
	return getNPosition(str, chr, n, 0, 0);
}

int main_S_09_09() {

	char* str = readText();
	char chr;
	int n;

	scanf_s("%c", &chr);
	scanf_s("%d", &n);
	int position = getNPositionWrapper(str, chr, n);
	printf("%d", position);
}