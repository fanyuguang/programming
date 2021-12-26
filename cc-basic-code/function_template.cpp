#include <iostream>
#include <string>

using namespace std;

template<typename T>
T max(T &a, T &b) {
  return b > a ? b : a;
}

int main() {
  int a = 1;
  int b = 2;
  cout << max(a, b) << endl;
  double c = 1.2;
  double d = 1.1;
  cout << max<double>(c, d) << endl;
  string e = "abc";
  string f = "def";
  cout << max<string>(e, f) << endl;
  return 0;
}
