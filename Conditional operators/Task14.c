#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������� ���� ���� ����� � �������� ���� �� ���� �� ���� �������� ���� ������� �� ����� ���� �����. ��� ������� � ����� �������, 
�������� �perfect square�, � �������� ������ �not a perfect square�.
*/
int main14()
{
	int number;
	scanf_s("%d", &number);

	int numberSquared = sqrt(number);
	int isNumberPerfectSquare = numberSquared * numberSquared == number;

	printf("%s", isNumberPerfectSquare ? "Yes" : "No");

}