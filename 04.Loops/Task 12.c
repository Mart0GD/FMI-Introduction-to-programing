#include<stdio.h>
#include<string.h>
#include<math.h>

//�������� ��������, ����� ������� ����� � ������� ��� �� ��������� � �� �������� � ��������� ������ �������.
int main12()
{
    char number[17]; 
    fgets(number, sizeof(number), stdin); // tazi zadacha ne e za sega PRETURSIH VSICHKO NE MOJE BEZ STRINGGGGGG

    int decimal = 0;
    for (int i = 0; i < strlen(number); i++)
    {
        decimal += ((int)number[i] - '0') * pow(2 , i);
    }
    
    printf("decimal -> %d", decimal);
}
