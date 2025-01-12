#include<stdio.h>

//Напишете програма, която по въведени 3 цели числа, принтира на конзолата числата в нарастващ ред.
int main4() {

	int num1, num2, num3;
	scanf_s("%d %d %d", &num1, &num2, &num3);

	int max = num1;
	int mid = num2;
	int min = num3;

	if (min > mid)
	{
		mid = min;
		min = num2;
	}
	if (mid > max)
	{
		max = mid;
		mid = num1;

		if (min > mid)
		{
			mid = min;
			min = num1;
		}
	}

	printf("%d %d %d", max, mid, min);
	return 0;
}