#include <iostream>

using namespace std;

int partition(int *array, int p, int r) {
  int i = p - 1;
  for (int j = p; j <= r; j++) {
    if (array[j] <= array[r]) {
      int temp = array[++i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  return i;
}

void quick_sort(int *array, int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}

int main() {
  int array[] = {1, 2, 4, 3, 8, 7, 6, 5};
  quick_sort(array, 0, 7);
  for (int i = 0; i < 8; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
