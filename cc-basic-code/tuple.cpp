#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
  tuple<int, double, string> data_store(1, 1.1, "hello world!");
  cout << get<0>(data_store) << " " << get<1>(data_store) << " " << get<2>(data_store) << endl; 
  data_store = make_tuple(2, 2.2, "cloue");
  cout << get<0>(data_store) << " " << get<1>(data_store) << " " << get<2>(data_store) << endl; 
  cout << "tuple size : " << tuple_size<decltype(data_store)>::value << endl;
  return 0;
}
