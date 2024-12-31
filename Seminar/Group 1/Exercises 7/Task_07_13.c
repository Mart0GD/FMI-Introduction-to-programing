#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)
/*
13. Да се напише програма, която за дадена числова редица a0, a1, ..., an-1 намира дължината на най-дългата ѝ ненамаляваща подредица ai1, ai2, ..., aik (ai1 <= ai2 <= ... <= aik), където i1 < i2 < … < ik.
*/

int* createArr5(const unsigned arrSize){
	int* arr = (int*)malloc(sizeof(int) * arrSize);
	if (!arr) return NULL;

	for (int i = 0; i < arrSize; i++){
		scanf("%d", &arr[i]);
	}

	return arr;
}

int findLongestSubsequenceLength(const int* arr, const unsigned arrSize) {

	int previousElement = arr[0];
	int sequenceLength = 1;
	for (int i = 1; i < arrSize; i++){

		if (previousElement < arr[i]){
			sequenceLength++;
		}
		else{
			sequenceLength = 1;
		}
		previousElement = arr[i];
	}

	return sequenceLength;
}

int main_07_13() {

	unsigned arrSize;

	puts("Insert array size: ");
	scanf("%u", &arrSize);

	int* arr = createArr5(arrSize);

	int longestSubsequenceLength = findLongestSubsequenceLength(arr, arrSize);
	printf("Longest nondecreasing subsequence has a length of --> %d", longestSubsequenceLength);
	free(arr);
	return 0;
}