#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main3()
{
	const int SizeOfUnsignedInt = sizeof(unsigned int) * 8;

	unsigned int firstChromosome;
	unsigned int secondChromosome;

	puts("Input two positive numbers representing chromosomes:");
	int result = scanf_s("%u %u", &firstChromosome, &secondChromosome);
	if (result != 2)
	{
		printf("invalid input!");
		return 1;
	}


	unsigned int firstChromosomeMask = firstChromosome;
	unsigned int secondChromosomeMask = secondChromosome;

	srand(time(NULL));
	int maxBitForCrossing = log2(firstChromosome > secondChromosome ? firstChromosome : secondChromosome) + 1;
	int randomPointOfCrossing = (1 + rand(time(NULL))) % maxBitForCrossing;
	int bitsToShift = SizeOfUnsignedInt - randomPointOfCrossing;

	firstChromosomeMask = (firstChromosome << bitsToShift) >> bitsToShift;
	secondChromosomeMask = (secondChromosomeMask << bitsToShift) >> bitsToShift;

	unsigned int firstChromosomeChild = secondChromosomeMask ^ ((firstChromosome >> randomPointOfCrossing) << randomPointOfCrossing);
	unsigned int secondChromosomeChild = firstChromosomeMask ^ ((secondChromosome >> randomPointOfCrossing) << randomPointOfCrossing);

	printf("First product of crossing: %x\n", firstChromosomeChild);
	printf("Second product of crossing: %x", secondChromosomeChild);
	return 0;
}