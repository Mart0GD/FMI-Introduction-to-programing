#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ���� ����� � ������� ����:

���� �� �� 5 � 3 -> "divisible by 5 and 3"
���� �� �� 5 -> "divisible by 5"
���� �� �� 3 -> "divisible by 3"
�� �� ���� � �� 2�� -> "not divisible by 5 or 3"
*/
int main2()
{
	int number;
	scanf_s("%d", &number);

	if (number % 3 == 0 && number % 5 == 0){
		printf("divisible by 5 and 3");
	}
	else if (number % 5 == 0){
		printf("divisible by 5");
	}
	else if (number % 3 == 0){
		printf("divisible by 3");
	}
	else {
		printf("not divisible by 5 or 3");
	}

	return 0;
}