#include<stdio.h>
#include<math.h>

int main2()
{
	unsigned int number;
	unsigned int n;

	scanf_s("%u %u", &number, &n);

	printf("<< -> %u\n", number << n);
	printf(">> -> %u", number >> n);

	return 0;
}
