#include<stdio.h>
#include<math.h>

//�������� ��������, ����� ������� �� ��������� ���� ����� � ��������� ���� ���� ����� � ������. � ��������� �� �������� �������� ������� �������� isPrime.

int isPrime(int number)
{
	int isPrime = 1;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			isPrime = 0;
			break;
		}
	}

	return isPrime;
}


int main5()
{
	int number;
	scanf_s("%d", &number);
	printf("%d", isPrime(number));

	return 0;
}