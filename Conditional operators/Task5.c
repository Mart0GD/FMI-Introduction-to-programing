#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ������ � �������� ���� �:

����� ����� -> "lowercase"
������ ����� -> "uppercase"
����� -> "digit"
���� ��� ������ -> "other symbol"
*/
int main5()
{
	char c;
	scanf_s("%c", &c);

	int isLowerCase = 'a' <= c && c <= 'z';
	int isUpperCase = 'A' <= c && c <= 'Z';
	int isDigit = '0' <= c && c <= '9';

	if (isLowerCase) { puts("lowercase"); }
	else if (isUpperCase) { puts("uppercase"); }
	else if (isDigit) { puts("digit"); }
	else { puts("other symbol"); }

	return 0;
}