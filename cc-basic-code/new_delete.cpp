#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
  Employee() {
    cout << "constructor" << endl;
  }

  ~Employee() {
    cout << "deconstructor" << endl;
  }
};

int main() {
  string* str_p = new string("hello world!");
  delete str_p;

  string* str_array_p = new string[3]{"a", "b", "c"};
  delete [] str_array_p;

  Employee* e_p = new Employee();
  delete e_p;

  Employee* e_array_p = new Employee[3];
  delete [] e_array_p;

  return 0;
}
