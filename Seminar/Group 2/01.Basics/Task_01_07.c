#include<stdio.h>

//������ 7: ������ �� ������. �� �� �������� 1, ��� � ��������� ������ �����, � 0, ��� �� �.
int main01_7() {

	char letter;
	scanf_s("%c", &letter);

	int minLowercase = 'a';
	int maxLowercase = 'z';

	int minUppercase = 'A';
	int maxUppercase = 'Z';

	printf("%d", (letter >= minLowercase && letter <= maxLowercase) || (letter >= minUppercase && letter <= maxUppercase));
	return 0;
}