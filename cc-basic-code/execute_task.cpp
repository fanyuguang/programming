// *We have a list of various types of tasks to perform. Task types are identified with an identifier: task of type A, task of type B, task of type C, etc. Each task takes 1 time slot to execute, and once we have executed a task we need cooldown (parameter) time slots to recover before we can execute another task of the same type. However, we can execute tasks of other types in the meantime. The recovery interval is the same for all task types. WE DO NOT REORDER THE TASKS: always execute in order in which we received them on input.*

// *Given a list of input tasks to run, and the cooldown interval, output the list where the tasks are in the correct time slot. Total number of time slots should be minimal. *

// Example:  
// Tasks: A, B, C, A, D
// cooldown: 3
// Output: A, B, C, _, A, D

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> executeTask(vector<string> tasks, int execute_time, int cooldown) {
  unordered_map<string, int> index_store;
  vector<string> execute_order_task;
  int current_index = 0;
  for (string task : tasks) {
    if (index_store.find(task) != index_store.end()) {
      int diff_index = execute_time + cooldown - current_index + index_store[task];
      if (diff_index > 0) {
        current_index += diff_index;
        while (diff_index-- > 0) {
          execute_order_task.push_back("_");
        }
      }
    }
    execute_order_task.push_back(task);
    index_store[task] = current_index;
    current_index++;
  }
  return execute_order_task;
}
  

int main() {
  vector<string> tasks = {"A", "B", "C", "A", "D"};
  vector<string> result = executeTask(tasks, 1, 3);
  for (string task : result) {
    cout << task << endl;
  }
  return 0;
}
