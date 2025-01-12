#include<stdio.h>

/*
Ќапишете програма, ко€то прочита ц€ло число n и пресм€та и принтира на конзолата следните суми:

1 + 2 + 3 + 4 + ... + n
1.2 + 2.3 + 3.4 + ... + n.(n+1)
1.2 + 3.4 + 5.6 + ... + (2n - 1).2n
1.2.3 + 2.3.4 + 3.4.5 + ... + n.(n+1).(n+2)
1! + 2! + 3! + ... + n!
*/
int main_3()
{
	int n;
	scanf_s("%d", &n);

	int sum1 = 0;

	for (int i = 1; i <= n; i++)
	{
		sum1 += i;
	}

	int sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		sum2 += i * (i + 1);
	}

	int sum3 = 0;
	for (int i = 1, k = 1; i <= n; i++, k+=2)
	{
		sum3 += (k * (k + 1));
	}

	int sum4 = 0;
	for (int i = 1; i <= n; i++)
	{
		sum4 += i * (i + 1) * (i + 2);
	}

	int sum5 = 0;
	for (int i = 1; i <= n; i++)
	{
		int currentFactorialSum = 1;
		for (int j = 1; j <= i; j++)
		{
			currentFactorialSum *= j;
		}
		sum5 += currentFactorialSum;
	}

	/*
	n -> 6
n(n-1) -> 8
(2n - 1).2n -> 44
n.(n+1).(n+2) -> 90
n! -> 9
*/

	printf("n -> %d\n", sum1);
	printf("n(n-1) -> %d\n", sum2);
	printf("(2n - 1).2n  %d\n", sum3);
	printf("n.(n+1).(n+2) %d\n", sum4);
	printf("n! -> %d\n", sum5);
	return;
}