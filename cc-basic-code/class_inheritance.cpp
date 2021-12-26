#include <iostream>

using namespace std;

class Base{
public:
  void print1() {
    cout << "Base public" << endl;
  }

protected:
  void print2() {
    cout << "Base protected" << endl;
  }

private:
  void print3() {
    cout << "Base private" << endl;
  }

};

class Subclass1 : public Base {
};

class Subclass2 : protected Base {
};

class Subclass3 : private Base {
};

int main() {
  Subclass1 s1;
  s1.print1();
  // s1.print2();
  // s1.print3();
  
  Subclass2 s2;
  // s2.print1();
  // s2.print2();
  // s2.print3();

  Subclass3 s3;
  // s3.print1();
  // s3.print2();
  // s3.print3();
  
  return 0;
}
