#include <iostream>
#include <cmath>

using namespace std;

void radix_sort(int *array, int size) {
	int **radix_array = new int*[10];
	for (int i = 0; i < 10; i++) {
		radix_array[i] = new int[size];
		radix_array[i][0] = 0;
	}
	int max_element = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
	}
	int pos_count = 0;
	while (max_element > 0) {
		pos_count++;
		max_element /= 10;
	}

	for (int pos = 0; pos < pos_count; pos++) {
		int pow_element = pow(10, pos);
		for (int i = 0; i < size; i++) {
			int pos_element = (array[i] / pow_element) % 10;
			int index = ++radix_array[pos_element][0];
			radix_array[pos_element][index] = array[i];
		}
		int k = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j <= radix_array[i][0]; j++) {
				array[k++] = radix_array[i][j];
			}
			radix_array[i][0] = 0;
		}
	}
}

int main() {
	int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
	radix_sort(array, 8);
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
