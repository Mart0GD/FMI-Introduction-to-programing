#include<stdio.h>

/*
3
  0 0 0 0 0 0 0 0 0 0  
  0	1             1 0
  0	1 2	        2 1 0  
  0	1 2 3 --- 3 2 1 0
  0	1 2	        2 1 0
  0	1			  1 0
  0				    0
*/
int main_03_11()
{
    int n;
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int p = 1;
        for (int j = 1; j <= i; j++)
            printf("%d ", p++);

        for (int j = i; j <= n; j++)
            printf("  ");

        for (int j = 1; j <= n; j++)
        {
            if (i == n)
                printf("- ");
            else
                printf("  ");
        }

        for (int j = i; j <= n; j++)
            printf("  ");

        for (int j = 1; j <= i; j++)
            printf("%d ", --p);

        printf("\n");
    }

    for (int i = 1; i < n; i++)
    {
        int p = 1;
        for (int j = i; j < n; j++)
            printf("%d ", p++);

        for (int j = 1; j <= i; j++)
            printf("  ");

        for (int j = 1; j <= n + 2; j++)
            printf("  ");

        for (int j = 1; j <= i; j++)
            printf("  ");

        for (int j = i; j < n; j++)
            printf("%d ", --p);

        printf("\n");
    }

    return 0;
}