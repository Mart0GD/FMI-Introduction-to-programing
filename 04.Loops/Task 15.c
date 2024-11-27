#include<stdio.h>

//Напишете програма, която прочита цяло положително число n и принтира първите n реда на триъгълника на Паскал в конзолата.
int main15()
{
	int rows;
	scanf_s("%d", &rows);

	if (rows == 0) { return; }

	int permutationN;
	int permutationK;
	int productOfNMinusKPermutation;
	for (int n = 0; n < rows; n++)
	{
		for (int k = 0; k < n; k++)
		{
			permutationN = 1;
			permutationK = 1;
			productOfNMinusKPermutation = 1;

			for (int i = n; i > 0; i--)
			{
				permutationN *= i;
			}
			for (int j = k; j > 0; j--)
			{
				permutationK *= j;
			}
			for (int m = n - k; m > 0; m--)
			{
				productOfNMinusKPermutation *= m;
			}

			printf("%d ", permutationN / (permutationK * productOfNMinusKPermutation));
		}
		printf("1");
		puts("");
	}
	return 0;
}