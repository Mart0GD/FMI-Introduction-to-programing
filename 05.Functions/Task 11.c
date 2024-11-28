#include<stdio.h>
#include<math.h>
#include<limits.h>
/*
P11
�������� ��������, ����� ������� �� ��������� ���� ����������� ����� � �������� �� ��������� ���-������� �� �������, ����� � �������� �� ������ �����. �������� � ����������� ������� largestDivisor, ����� ������ ���� ����� ���� �������� � ����� ���� �����.
*/

int findLargestDivisor(int n) {
	if (n == 0)
	{
		puts("No divisor can be calculated!");
		return 0;
	}
	else if (n % 2 == 0)
	{
		return n / 2;
	}

	int largestDivisor = INT_MIN;
	int sqrtOfN = sqrt(n);
	for (int i = n - 1; i >= 1; i--)
	{
		if (n % i == 0)
		{
			return i;
		}
	}
}
int main_11() 
{
	int n = 0;
	scanf_s("%d", &n);

	printf("The largest divisor is -> %d", findLargestDivisor(n));
	return 0;
}