#include <iostream>

using namespace std;

void print(int val) {
  cout << "int" << endl;
}

void print(int *p) {
  cout << "int*" << endl;
}

int main() {
  print(0);
  // print(NULL);
  print(nullptr);
  return 0;
}
