#include <iostream>
#include <string>

using namespace std;

class S {
public:
  void print() {
    cout << "S str : " << str << endl;
    cout << "str address : " << &str << endl << endl;

    // Capture the this pointer of the enclosing class
    [this] {
      cout << "this str : " << str << endl;
      cout << "str address : " << &str << endl << endl;
    }();
  }

private:
  string str = "hello world!";
};

int main() {
  string str = "hello world!";
  cout << "str : " << str << endl;
  cout << "str address : " << &str << endl << endl;

  [] {
    cout << "hello world!" << endl << endl;
  }();

  // Capture nothing
  auto func1 = [] (string str) {
    cout << "func1 str : " << str << endl;
    cout << "str address : " << &str << endl << endl;
  };
  func1(str);

  // Capture any referenced variable by making a copy
  auto func2 = [=] {
    cout << "func2 str : " << str << endl;
    cout << "str address : " << &str << endl << endl;
  };
  func2();
  
  // Capture any referenced variable by reference
  auto func3 = [&] {
    cout << "func3 str : " << str << endl;
    cout << "str address : " << &str << endl << endl;
  };
  func3();
  
  // Capture bar by making copy, don't copy anythin else
  auto func4 = [str] {
    cout << "func4 str : " << str << endl;
    cout << "str address : " << &str << endl << endl;
  };
  func4();

  S s;
  s.print();
  return 0;
}
