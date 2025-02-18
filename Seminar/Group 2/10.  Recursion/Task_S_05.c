

/*
Задача 5 (Двоично търсене): Да се напише рекурсивна функция, която приема сортиран масив от числа и число n и връща дали n се съдържа в масива.
Вход: 5 10 15 20 22 30     5, Изход: true
Вход: 5 10 15 20 22 30     16, Изход: false
*/

int binarySearchRec(int arr[], int left, int right, int num) {
	if (left > right) return 0;

	int mid = (left + right) / 2;

	if (arr[mid] == num) return 1;
	else if (arr[mid] < num) binarySearchRec(arr, mid + 1, right, num);
	else if (arr[mid] > num) binarySearchRec(arr, left, mid - 1, num);
}

int main_S_05() {

	int arr[6] = { 5, 10, 15, 20, 22, 30 };

	int isIn = binarySearchRec(arr, 0, 5, 10);
	printf("%d", isIn);
	return 0;
}