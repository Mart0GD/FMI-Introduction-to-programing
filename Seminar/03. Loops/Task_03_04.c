#include<stdio.h>

/*
������ 4: �� �� ������ ��������, ����� ��� �������� ���� ����������� ����� n ��������� ���� ������� � ���������.
����: 34543, �����: 1
����: 111, �����: 1
����: 12345, �����: 0
*/
int main_04_05()
{
	int number = 0;
	scanf_s("%d", &number);

	int numberCopy = number;
	int numberReversed = 0;
	while (numberCopy != 0)
	{
		numberReversed *= 10;
		numberReversed += numberCopy % 10;
		numberCopy /= 10;
	}

	if (number == numberReversed){
		puts("1");
	}
	else{
		puts("0");
	}


	return 0;
}