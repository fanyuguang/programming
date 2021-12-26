#include <iostream>

using namespace std;

void bubble_sort(int *array, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = size - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        int temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
}

int main() {
  int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
  bubble_sort(array, 8);
  for (int i = 0; i < 8; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
