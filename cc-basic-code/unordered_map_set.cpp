#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
  unordered_map<int, string> hash_map;
  hash_map.insert(make_pair(1, "a"));
  hash_map[2] = "b";
  for (unordered_map<int, string>::iterator iter = hash_map.begin(); iter != hash_map.end(); iter++) {
    cout << "first : " << iter->first << " second : " << iter->second << endl;
  }
  for (pair<int, string> iter : hash_map) {
    cout << "first : " << iter.first << " second : " << iter.second << endl;
  }

  unordered_set<int> hash_set;
  hash_set.insert(1);
  hash_set.insert(2);
  for (int num : hash_set) {
    cout << num << endl;
  }

  return 0;
}
