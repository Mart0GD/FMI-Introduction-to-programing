#include<stdio.h>
#include<math.h>
/*
�������� ��������, ����� ������� �� ��������� ���� ������������� ����� n, ���� ����� �������� ������ ������������ �� ������ ��������� �� n ��������. ���� ���������� �� �� ������� �� 1 �� n.

���������: ��������� ����� �� � ������������ �� �� � ������ ��� ���� ��������������.
#1 ������
����:
3

�����:
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