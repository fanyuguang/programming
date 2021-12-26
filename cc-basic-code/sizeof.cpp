#include <iostream>
#include <string>

using namespace std;

class EmptyClass {
};

class Employee {
public:
  int id_;
};

class Leader {
public:
  Leader(int id, string str) : id_(id), str_(str) {}
  int id_;
  string str_;
};

class VirtualClass {
public:
  virtual void Print() {
  }
};

int main() {
  int i;
  cout << "int i : " << sizeof(i) << endl;
  i = 1;
  cout << "int i : " << sizeof(i) << endl;

  long l;
  cout << "long l : " << sizeof(l) << endl;
  l = 1l;
  cout << "long l : " << sizeof(l) << endl;

  float f;
  cout << "float f : " << sizeof(f) << endl;
  f = 1.1f;
  cout << "float f : " << sizeof(f) << endl;

  double d;
  cout << "double d : " << sizeof(d) << endl;
  d = 1.1;
  cout << "double d : " << sizeof(d) << endl;

  char c;
  cout << "char c : " << sizeof(c) << endl;
  c = 'a';
  cout << "char c : " << sizeof(c) << endl;

  string str;
  cout << "string str : " << sizeof(str) << endl;
  str = "a";
  cout << "string str : " << sizeof(str) << endl;

  int* p;
  cout << "pointer p : " << sizeof(p) << endl;

  EmptyClass empty_class;
  cout << "class EmptyClass : " << sizeof(empty_class) << endl;

  Employee e;
  cout << "class Employee : " << sizeof(e) << endl;

  Leader* leader = new Leader(1, "a");
  cout << "class Leader pointer : " << sizeof(leader) << endl;
  Leader leader2 = Leader(1, "a");
  cout << "class Leader : " << sizeof(leader2) << endl;

  VirtualClass v;
  cout << "class Virtual : " << sizeof(v) << endl;

  return 0;
}
