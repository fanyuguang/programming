#include <iostream>

using namespace std;

class Employee{
public:
  Employee(int id_val, int score_val) {
    id = id_val;
    score = score_val;
  }

  Employee operator+(Employee& e2) {
    Employee e3(id, score + e2.score);
    return e3;
  }

  int get_id() {
    return id;
  }

  int get_score() {
    return score;
  }

  friend bool operator<(const Employee& e1, const Employee& e2);

private:
  int id;
  int score;
};

bool operator<(const Employee& e1, const Employee& e2) {
  return e1.score < e2.score;
}

int main() {
  Employee e1(1, 90);
  Employee e2(2, 91);
  if (e1 < e2) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  Employee e3 = e1 + e2;
  cout << e3.get_score() << endl;
  return 0;
}
