#include <iostream>
#include <cstring>

using namespace std;

void counting_sort(int *array, int size) {
	int max_element = array[0];
	int min_element = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
		if (array[i] < min_element) {
			min_element = array[i];
		}
	}
	int count_array_size = max_element - min_element + 1;
	int count_array[count_array_size];
	//for (int i = 0; i < count_array_size; i++) {
	//	count_array[i] = 0;
	//}
	memset(count_array, 0, count_array_size * sizeof(int));
	for (int i = 0; i < size; i++) {
		count_array[array[i] - min_element]++;
	}
	for (int i = 1; i < count_array_size; i++) {
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	int array_copy[size];
	for (int i = 0; i < size; i++) {
		array_copy[i] = array[i];
	}
	for (int i = 0; i < size; i++) {
		array[count_array[array_copy[i] - min_element] - 1] = array_copy[i];
		count_array[array_copy[i] - min_element]--;
	}
}

int main() {
	int array[] = {1, 2, 4, 3, 6, 5, 8, 7};
	counting_sort(array, 8);
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
