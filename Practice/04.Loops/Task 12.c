#include<stdio.h>
#include<string.h>
#include<math.h>

//Напишете програма, която прочита число в двоичен вид от конзолата и го превръща в десетична бройна система.
int main_12()
{
    long long number; 
    scanf_s("%lld", &number);

    int decimal = 0;
    int step = 0;
    int currentDigit = 0;
    while (number != 0)
    {
        currentDigit = (number % 10);
        if (currentDigit != 0 || currentDigit != 1)
        {
            puts("Not a binary number!");
            return 0;
        }

        decimal +=  currentDigit * pow(2, step);
        number /= 10;

        step++;
    }
    
    printf("decimal -> %d", decimal);
}
