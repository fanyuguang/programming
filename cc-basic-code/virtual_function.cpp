#include <iostream>

using namespace std;

class Employee {
public:
  Employee() {
    cout << "Employee constructor" << endl;
  }

  virtual ~Employee() {
    cout << "Employee deconstructor" << endl;
  }

  virtual void print() {
    cout << "Employee" << endl;
  }

  virtual void print_employee() = 0;
};

class Person {
public:
  Person() {
    cout << "Person constructor" << endl;
  }

  virtual ~Person() {
    cout << "Person deconstructor" << endl;
  }

  virtual void print() {
    cout << "Person" << endl;
  }

  virtual void print_person() {
    cout << "print_person" << endl;
  }
};

class Engineer : public Employee, public Person {
public:
  Engineer() {
    cout << "start" << endl;
    cout << "Engineer constructor" << endl;
    print();
    print_engineer();
    cout << "end" << endl;
  }

  ~Engineer() {
    cout << "Engineer deconstructor" << endl;
  }

  void print() {
    cout << "Engineer" << endl;
  }

  virtual void print_engineer() {
    cout << "print_engineer" << endl;
  }

  void print_employee() {
    cout << "print_employee" << endl;
  }
};

int main() {
  Engineer e;
  e.print();
  e.print_engineer();
  e.print_employee();
  e.print_person();

  Employee *e1 = new Engineer();
  e1->print();
  delete e1;
  cout << "done" << endl;

  return 0;
}
