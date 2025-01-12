#include<stdio.h>
#include<math.h>
/*
Напишете програма, която прочита от конзолата цяло неотрицателно число n, след което принтира всички подмножества на дадено множество от n елемента. Като елементите ще са числата от 1 до n.

ЗАБЕЛЕЖКА: Изходните данни не е задължително да са в същият ред като долупоказаните.
#1 Пример
Вход:
3

Изход:
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }

{ 4 }
{ 1 2 3 4 }
{ 1 2 4 }
{ 1 3 4 }
{ 2 3 4 }
{ 1 4 }
{ 2 4 }
{ 3 4 }
*/
int main() 
{
    unsigned n = 0;

    scanf("%u", &n);

    const unsigned k_subsetsCount = 1 << n;

    for (unsigned subsetMask = 0; subsetMask < k_subsetsCount; ++subsetMask) {
        printf("{ ");

        for (unsigned bitIndex = 0; bitIndex < n; ++bitIndex) {
            if (subsetMask & (1 << bitIndex)) {
                unsigned subsetElement = bitIndex + 1;

                printf("%d ", subsetElement);
            }
        }

        printf("}\n");
	
	
	return 0;
}