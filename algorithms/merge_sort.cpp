#include <iostream>

using namespace std;

void merge(int *a, int begin, int mid, int end) {
  int n1 = mid - begin + 1;
  int n2 = end - mid;
  int array1[n1];
  int array2[n2];
  for (int i = 0; i < n1; i++) {
    array1[i] = a[begin + i];
  }
  for (int j = 0; j < n2; j++) {
    array2[j] = a[mid + j + 1];
  }
  int i = 0;
  int j = 0;
  while (i < n1 && j < n2) {
    if (array1[i] <= array2[j]) {
      a[begin + i + j] = array1[i];
      i++;
    } else {
      a[begin + i + j] = array2[j];
      j++;
    }
  }
  if (i == n1 && j < n2) {
    while (j < n2) {
      a[begin + i + j] = array2[j];
      j++;
    }
  } else if (i < n1 && j == n2) {
    while (i < n1) {
      a[begin + i + j] = array1[i];
      i++;
    }
  } else {
  }
}

void merge_sort(int *a, int begin, int end) {
  if (begin < end) {
    int mid = (begin + end) / 2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid + 1, end);
    merge(a, begin, mid, end);
  }
}

int main() {
  int a[] = {1, 2, 4, 3, 8, 7, 6, 5};
  merge_sort(a, 0, 7);
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
