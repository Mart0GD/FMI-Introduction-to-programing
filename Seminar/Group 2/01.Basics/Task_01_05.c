#include<stdio.h>

/*
������ 5: ������� �� ���� ����� n - n ����. �� �� ������ �� ��������� ��� ���� ������ �� �� ������� �� ��������, ���� �� �� ����� ��������� ����. � ��������� ��������, �� ����� � �������� �� 1 � 2 ����.
����: 193, �����: 1x100, 1x50, 2x20, 0x5, 1x2, 1x1
*/
int main01_5()
{
	int money;
	scanf_s("%d", &money);

	int hundredsCount = money / 100;
	money -= 100 * hundredsCount;

	int fiftiesCount = money / 50;
	money -= 50 * fiftiesCount;

	int twentiesCount = money / 20;
	money -= 20 * twentiesCount;

	int tensCount = money / 10;
	money -= 10 * tensCount;

	int fivesCount = money / 5;
	money -= 5 * fivesCount;

	int twosCount = money / 2;
	money -= 2 * twosCount;

	int onesCount = money;

	printf("%dx100, %dx50, %dx20, %dx10, %dx5, %dx2, 1x%d", hundredsCount, fiftiesCount, twentiesCount, tensCount, fivesCount, twosCount, onesCount);
	return 0;
}