#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Stack {
public:
  Stack() {
    max_size = 5;
    data_store = new T[max_size];
    top_p = 0;
  }

  ~Stack() {
    delete [] data_store;
    data_store = NULL;
  }

  void expand_capacity() {
    max_size = max_size * 3 / 2;
    T *new_data_store = new T[max_size];
    copy(data_store, data_store + top_p, new_data_store);
    delete [] data_store;
    data_store = new_data_store;
  }

  void push(T val) {
    if (top_p >= max_size) {
      expand_capacity();
    }
    data_store[top_p++] = val;
  }

  void pop() {
    if (top_p > 0) {
      top_p--;
    }
  }

  T top() {
    return data_store[top_p - 1];
  }

  bool empty() {
    return top_p <= 0;
  }

  int size() {
    return top_p;
  }

private:
  T *data_store;
  int max_size;
  int top_p;
};

int main() {
  // Stack<int> s;
  // s.push(1);
  // s.push(2);
  // s.push(3);
  // s.push(4);
  // s.push(5);
  // s.push(6);
  Stack<string> s;
  s.push("a");
  s.push("b");
  s.push("c");
  s.push("d");
  s.push("d");
  s.push("e");
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}
