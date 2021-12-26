#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Employee {
public:
  Employee (string name_val) {
    name = name_val;
  }
  void print() {
    cout << "hello " << name << endl;
  }

private:
  string name;
};

int main() {
  // unique_ptr
  unique_ptr<Employee> s_p1(new Employee("employee1"));
  if (s_p1.get()) {
    s_p1->print();
  }
  unique_ptr<Employee> s_p2 = move(s_p1);
  if (s_p1.get()) {
    cout << "s_p1 : ";
    s_p1->print();
  }
  if (s_p2.get()) {
    cout << "s_p2 : ";
    s_p2->print();
  }

  unique_ptr<string> s_p3(new string("hello world!"));
  string *s1 = s_p3.get();
  cout << "string : " << *s1 << endl;
  
  // shared_ptr
  // shared_ptr<Employee> s_p4(new Employee("employee2"));
  shared_ptr<Employee> s_p4 = make_shared<Employee>("employee2");
  if (s_p4.get()) {
    s_p4->print();
  }
  cout << "s_p4, count of reference : " << s_p4.use_count() << endl;
  shared_ptr<Employee> s_p5 = s_p4;
  if (s_p4.get()) {
    cout << "s_p4 : ";
    s_p4->print();
  }
  if (s_p5.get()) {
    cout << "s_p5 : ";
    s_p5->print();
  }

  // change unique_ptr to shared_ptr
  shared_ptr<Employee> s_p6 = move(s_p2);
  if (s_p2.get()) {
    cout << "s_p2 : ";
    s_p2->print();
  }
  if (s_p6.get()) {
    cout << "s_p6 : ";
    s_p6->print();
  }

  shared_ptr<string> s_p7(new string("hello world!"));
  string *s2 = s_p7.get();
  cout << "string : " << *s2 << endl;

  // weak_ptr
  weak_ptr<Employee> s_p8 = s_p4;
  if (!s_p8.expired()) {
    cout << "s_p8 : ";
    s_p8.lock()->print();
  }
  cout << "s_p8, count of reference : " << s_p8.use_count() << endl;
  shared_ptr<Employee> s_p9 = s_p8.lock();
  if (s_p9.get()) {
    cout << "s_p9 : ";
    s_p9->print();
  }

  return 0;
}
