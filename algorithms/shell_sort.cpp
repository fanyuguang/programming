#include <iostream>

using namespace std;

void shell_insert(int *array, int step, int size) {
	for (int i = step; i < size; i++) {
		int element_copy = array[i];
		int j;
		for (j = i - step; j >= 0 && array[j] > element_copy; j = j - step) {
			array[j + step] = array[j];
		}
		array[j + step] = element_copy;
	}
}

void shell_sort(int *array, int size) {
	int step = size / 2;
	while (step > 0) {
		shell_insert(array, step, size);
		step = step / 2;
	}
}

int main() {
	int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
	shell_sort(array, 8);
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
