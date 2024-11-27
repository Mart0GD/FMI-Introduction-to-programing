#include<stdio.h>
#include<math.h>

int main14()
{
	int n;
	scanf_s("%d", &n);

	int rows = (2 * n) - 1;
	int step = 0;
	int beginningCell = ceil(rows / 2);
	int middleRow = beginningCell; // suchtata smetka
	int modifier = 1;

	for (int i = 0; i < rows; i++)
	{
		if (i == middleRow) { modifier = -1; }

		for (int j = 0; j < rows; j++)
		{
			if ((i == 0 || i == rows - 1) && j == beginningCell){
				printf("*");
			}
			else if (i != 0 && i != rows -1 && (j >= beginningCell - step && j <= beginningCell + step)) {
				printf("*");
			}
			else{
				printf(" ");
			}
		}

		step += (1 * modifier);
		puts("");
	}
}