#include<stdio.h>

int main()
{
	unsigned int n;
	unsigned short k;

	puts("Plsease, insert values for N and K: ");
	int result = scanf_s("%u %hu", &n, &k);
	if (result != 2 || k == 0 || k > 32)
	{
		puts("Invalid input!");
		return 1;
	}

	int numberOfOnesInsideBinaryRepresentation =
		((n >> 32) & 1) +
		((n >> 31) & 1) +
		((n >> 30) & 1) +
		((n >> 29) & 1) +
		((n >> 28) & 1) +
		((n >> 27) & 1) +
		((n >> 26) & 1) +
		((n >> 25) & 1) +
		((n >> 24) & 1) +
		((n >> 23) & 1) +
		((n >> 22) & 1) +
		((n >> 21) & 1) +
		((n >> 20) & 1) +
		((n >> 19) & 1) +
		((n >> 18) & 1) +
		((n >> 17) & 1) +
		((n >> 16) & 1) +
		((n >> 15) & 1) +
		((n >> 14) & 1) +
		((n >> 13) & 1) +
		((n >> 12) & 1) +
		((n >> 11) & 1) +
		((n >> 10) & 1) +
		((n >> 9) & 1) +
		((n >> 8) & 1) +
		((n >> 7) & 1) +
		((n >> 6) & 1) +
		((n >> 5) & 1) +
		((n >> 4) & 1) +
		((n >> 3) & 1) +
		((n >> 2) & 1) +
		((n >> 1) & 1);



	int isOperationPossible = 1;
	if (k > n) { isOperationPossible = 0; }
	else if (numberOfOnesInsideBinaryRepresentation > k){ isOperationPossible = 0; }

	printf("%s", isOperationPossible == 1 ? "True" : "False");
	return 0;
}