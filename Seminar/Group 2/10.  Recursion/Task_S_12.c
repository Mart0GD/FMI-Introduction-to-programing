#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
/*
����������� � ����������, ����� ���� �� ��������� �������� ��������:

��������� �� ����� X �� 2
��������� �� ����� X �� 3
�������� �� ����� X � 1-��
������ � ���� ����������� ����� n. ���������� ���������, ����� �������� ���- ������ ���� ��������, ����� ������ �� ��������, �� �� ������� ������� n (��������� ����������� �� ���������� �� ������� 1).

������:
����: 962340
�����: 17

��������� ��� �������:
1 -> 3 -> 9 -> 27 -> 54 -> 55 -> 165 -> 495 -> 1485 -> 4455 -> 8910 -> 17820 -> 17821 -> 53463 -> 160389 -> 160390 -> 481170 -> 962340
*/
unsigned int getMinimumOperations(unsigned int n){
    unsigned* minOperations = (unsigned*)malloc((n + 1) * sizeof(unsigned));
    if (!minOperations) return 0;

    for (int i = 0; i <= n; i++){
        minOperations[i] = UINT_MAX;
    }

    minOperations[1] = 0;
    minOperations[2] = 1;
    minOperations[3] = 1;

    unsigned min1;
    unsigned min2;
    unsigned min3;
    unsigned min = 0;
    for (int i = 4; i <= n; i++){

        min1 = i % 3 == 0 ? minOperations[i / 3] : UINT_MAX;
        min2 = i % 2 == 0 ? minOperations[i / 2] : UINT_MAX;
        min3 = minOperations[i - 1];

        min = min1;
        if (min2 < min) min = min2;
        if (min3 < min) min = min3;

        minOperations[i] = 1 + min;
    }

    return minOperations[n];
} 

int main_S_12()
{
    printf("The minimum number of operations is %u\n", getMinimumOperations(962340));
    return 0;
}