#include <iostream>

using namespace std;

int main() {
  auto a = 1;
  decltype(a) b = 2;
  cout << a + b << endl;

  auto strs = {"hello", "world"};
  for (const string& str : strs) {
    cout << str << endl;
  }
  return 0;
}
