#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  // pair
  pair<int, string> p(1, "hello");
  cout << "pair first : " << p.first << " second : " << p.second << endl;
  p = make_pair(2, "world!");
  cout << "pair first : " << p.first << " second : " << p.second << endl;

  map<int, string> data_store;
  // map insert
  data_store.insert(p);
  data_store[3] = "cloud";
  cout << "map find : " << data_store[3] << endl;
  // iterator
  for(map<int, string>::iterator iter = data_store.begin(); iter != data_store.end(); iter++) {
    cout << "map first : " << iter->first << " second : " << iter->second << endl;
  }
  // map delete
  data_store.erase(3);
  for (pair<int, string> iter : data_store) {
    cout << "map first : " << iter.first << " second : " << iter.second << endl;
  }
  // map size
  cout << "size : " << data_store.size() << endl;
  return 0;
}
