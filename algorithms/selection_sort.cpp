#include <iostream>

using namespace std;

void selection_sort(int *array, int size) {
  for (int i = 0; i < size; i++) {
    int index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[index]) {
        index = j;
      }
    }
    int temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
}

int main() {
  int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
  selection_sort(array, 8);
  for (int i = 0; i < 8; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
