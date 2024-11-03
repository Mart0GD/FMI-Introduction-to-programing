#include<stdio.h>

int main4()
{
	const int PARENT_BIT_SHIFT_LENGTH = 31;
	const int MASK = 1;

	unsigned int number;  //0b00000000000000000000000000001011;
//						    0b00000000000000000000000000000001;
	unsigned int n;

	scanf_s("%u %u", &number, &n);

	unsigned int parentBit = number >> PARENT_BIT_SHIFT_LENGTH;

	// nth
	int maskForNthBit = MASK << n;
	int nthBit = (number & maskForNthBit) >> n;

	// child
	int childBit = number & MASK;

	printf("youngest bit -> %u\n", childBit);
	printf("most significant bit -> %u\n", parentBit);
	printf("nth bit -> %u\n", nthBit);

	return 0;
}