#include<stdio.h>
#include<math.h>

/*
Напишете програма, която прочита цяло положително число n и принтира/рисува на конзолата диамант (диамантът има 2*n-1 реда). Рисувайте диамантът използвайки '*', като всеки ред има нечетен брой '*' и е коректно центриран спрямо другите редове.
*/
int main_14()
{
	int n;
	scanf_s("%d", &n);

	int rows = (2 * n) - 1;
	int step = 0;
	int beginningCell = ceil(rows / 2);
	int middleRow = beginningCell; 
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