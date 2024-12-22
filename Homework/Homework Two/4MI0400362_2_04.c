#include<stdio.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)
#define EPSILON 1E-9
#define FLOATING_POINT_MAX_FRACTION_INDEX 22

int checkForAllOneBits(const int number, const unsigned startIndex, const unsigned endIndex) {

	for (int i = startIndex; i <= endIndex; i++) {
		if (!((number >> i) & 1)){
			return 0;
		}
	}

	return 1;
}

int checkForAllZeroBits(const int number, const unsigned startIndex, const unsigned endIndex) {

	for (int i = startIndex; i <= endIndex; i++) {
		if ((number >> i) & 1){
			return 0;
		}
	}

	return 1;
}

int checkForFractionPart(const int* fractionArr, const unsigned arrSize){

	for (int i = 0; i < arrSize; i++){
		if (fractionArr[i] != 0){
			return 1;
		}
	}

	return 0;

}

long double calculateF(const int sign, int* Exponent, float* Mantissa, const  unsigned short m, const unsigned short n, const unsigned short e) {

	long double F = 0;

	if (checkForAllOneBits(*Exponent, m, n - 2)) {

		if (Mantissa == 0) {
			printf("%lf", sign * INFINITY);
			return INFINITY;
		}
		else {
			printf("NaN");
			return INFINITY;
		}
	}
	else if (checkForAllZeroBits(*Exponent, m, n - 2)) {
		F = sign * pow(2, -(pow(2, e - 1) - 2)) * *(Mantissa);
	}
	else {
		*Exponent = *Exponent - (pow(2, e - 1) - 1);
		*Mantissa = 1 + *Mantissa;
		F = sign * pow(2, *Exponent) * *(Mantissa);
	}

	return F;
}

void printFraction(const int* fractionArr, const unsigned arrSize) {

	for (int i = 0; i < arrSize; i++){
		printf("%d", fractionArr[i]);
	}
}

void printWholePartInBinary(long long number) {
	if (number == 0) {
		printf("0");
		return;
	}

	while (number){
		printf("%lld", number % 2);
		number /= 2;
	}
}

void printNumber(long double F) {

	long long wholePartOfF = (long long)F;
	puts("Output: ");
	printWholePartInBinary(wholePartOfF);

	float floatingPointPartOfF = wholePartOfF != 0 ? F - wholePartOfF : F;
	int binaryRepresentation[FLOATING_POINT_MAX_FRACTION_INDEX] = { 0 };
	int iter = 0;
	while (floatingPointPartOfF >= EPSILON) {
		floatingPointPartOfF *= 2;

		binaryRepresentation[iter++] = (int)floatingPointPartOfF;
		floatingPointPartOfF -= (int)floatingPointPartOfF;
	}

	if (checkForFractionPart(binaryRepresentation, FLOATING_POINT_MAX_FRACTION_INDEX)) {
		printf(".");
		printFraction(binaryRepresentation, iter);
	}

}

int main() {
	const unsigned short LONG_LONG_SIZE = sizeof(long long) * 8;
	const unsigned short MIN_N_SIZE = 8;
	const unsigned short MAX_N_SIZE = 64;

	unsigned short n,e;
	long long N;

	printf("Insert the binary size: ");
	if (scanf("%hu", &n) != 1 || n < MIN_N_SIZE || n > MAX_N_SIZE){
		puts("Inavlid input!");
		return -1;
	}

	const unsigned short MIN_E_SIZE = 2;
	const unsigned short MAX_E_SIZE = n - 2;

	printf("Insert the bits of the shifted exponent: ");
	if (scanf("%hu", &e) != 1 || e < MIN_E_SIZE || e > MAX_E_SIZE){
		puts("Inavlid input!");
		return -1;
	}

	printf("Insert number N(Hexadecimal): ");
	if (scanf("%llx", &N) != 1){
		puts("Inavlid input!");
		return -1;
	}

	int msb = (N >> (n - 1)) & 1;
	int sign = pow(-1, msb);
	int m = n - e - 1;

	unsigned long long E = (N << (LONG_LONG_SIZE - (n - 1)));
	E >>= (LONG_LONG_SIZE - (n - 1 - e));

	unsigned long long SBites = N << (LONG_LONG_SIZE - m);
	SBites >>= LONG_LONG_SIZE - m;	// mantissa bits

	long double S = 0; // mantissa as float
	int iter = 1;
	while (m){ 
		S += ((SBites >> (--m)) & 1) * pow(2, -iter);
		iter++;
	}

	long double F = calculateF(sign, &E, &S, m, n, e);

	if (F != INFINITY) {
		printNumber(F);
	}

	return 0;
}

// 0000 0000 0000 0000 1100 0001 0111 1101 0000 1001 0000 1110 0100 1000 0000 0000
// 0000 0000 0000 0000 0000 0000 0001 1101 0000 1001 0000 1110 0100 1000 0000 0000