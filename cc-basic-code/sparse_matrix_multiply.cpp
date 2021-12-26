#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
  int first_point;
  int second_point;
  Point (int x, int y) : first_point(x), second_point(y) {}
};

struct HashFunc {
  size_t operator()(const Point& p) const {
    return ((hash<int>()(p.first_point) ^ (hash<int>()(p.second_point) << 1)) >> 1);
  }
};

struct EqualPoint {
  bool operator ()(const Point& p1, const Point& p2) const {
    return p1.first_point == p2.first_point && p1.second_point == p2.second_point;
  }
};

class SparseMatrixOperator {
public:
  vector<vector<int>> SparseMatrixMultiply(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int m, int n, int r) {
    vector<vector<int>> matrix_multiply;
    unordered_map<Point, int, HashFunc, EqualPoint> matrix_store1;
    for (vector<int> iter : matrix1) {
      Point p(iter[0], iter[1]);
      matrix_store1[p] = iter[2];
    }
    unordered_map<Point, int, HashFunc, EqualPoint> matrix_store2;
    for (vector<int> iter : matrix2) {
      Point p(iter[0], iter[1]);
      matrix_store2[p] = iter[2];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < r; j++) {
        int element_multiply = 0;
        for (int k = 0; k < n; k++) {
          Point p1(i, k);
          Point p2(k, j);
          if (matrix_store1.find(p1) != matrix_store1.end() && matrix_store2.find(p2) != matrix_store2.end()) {
            element_multiply += matrix_store1[p1] * matrix_store2[p2];
          }
        }
        if (element_multiply != 0) {
          matrix_multiply.push_back({i, j, element_multiply});
        }
      }
    }
    return matrix_multiply;
  }

  void print(vector<vector<int>>& matrix, int m, int n) {
    unordered_map<Point, int, HashFunc, EqualPoint> element_store;
    for (vector<int> iter : matrix) {
      Point p(iter[0], iter[1]);
      element_store[p] = iter[2];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        Point p(i, j);
        if (element_store.find(p) != element_store.end()) {
          cout << element_store[p] << " ";
        } else {
          cout << "0" << " ";
        }
      }
      cout << endl;
    }
  }
};

int main() {
  // matrix1
  // 1 0
  // 0 2
  // 0 0
  vector<vector<int>> matrix1 = {{0, 0, 1}, {1, 1, 2}};
  // matrix2
  // 3 0 0 4
  // 0 0 5 0
  vector<vector<int>> matrix2 = {{0, 0, 3}, {0, 3, 4}, {1, 2, 5}};
  SparseMatrixOperator sparse_matrix_operator;
  vector<vector<int>> matrix_multiply =  sparse_matrix_operator.SparseMatrixMultiply(matrix1, matrix2, 3, 2, 4);
  cout << "matrix1:" << endl;
  sparse_matrix_operator.print(matrix1, 3, 2);
  cout << "matrix2:" << endl;
  sparse_matrix_operator.print(matrix2, 2, 4);
  cout << "matrix_multiply:" << endl;
  sparse_matrix_operator.print(matrix_multiply, 3, 4);
  return 0;
}
