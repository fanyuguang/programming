#include <iostream>

using namespace std;

void insertion_sort(int *array, int size) {
  for (int j = 2; j < size; j++) {
    int element_copy = array[j];
    for (int i = j - 1; i > 0; i--) {
      if (array[i] > element_copy) {
        array[i + 1] = array[i];
      } else {
        array[i + 1] = element_copy;
        break;
      }
    }
  }
}

int main() {
  int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
  insertion_sort(array, 8);
  for (int i = 0; i < 8; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
