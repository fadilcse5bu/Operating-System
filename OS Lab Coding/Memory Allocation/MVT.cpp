// Memory Allocation Algorithm
// Multi-Programming with Variable number of Tasks (MVT)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int total_memory;
  cout << "Enter Total Memory: ";
  cin >> total_memory;
  int free_memory = total_memory;  // initially no process is allocated

  map <int, int> allocated_process_size;
  int type;  // operation type

  cout << endl << "Enter 1 to allocate a process" << endl;
  cout << "Enter 2 to remove a process" << endl;
  cout << "Enter any other character to exit" << endl << endl;

  while(1) {
    cout << "Enter the operation type: ";
    cin >> type;

    // to allocate a process
    if(type == 1) {
      int process_id, process_size;
      cout << "Enter Process Id and Process Size: ";
      cin >> process_id >> process_size;
      cout << endl;

      if(allocated_process_size[process_id] > 0) {
        cout << "Process " << process_id << " is already running." << endl;
      }
      else if(free_memory >= process_size) {
        free_memory -= process_size;
        allocated_process_size[process_id] = process_size;
        cout << "Process " << process_id << " is allocated successfully." << endl;
      }
      else {
        cout << "Process " << process_id << " cannot be allocated." << endl;
      }
    }

    // to remove an allocated process
    else if(type == 2) {
      cout << "Enter Process Id: ";
      int process_id;
      cin >> process_id;
      cout << endl;

      if(allocated_process_size[process_id] > 0) {
        free_memory += allocated_process_size[process_id];
        cout << "Process " << process_id << " is removed successfully which size was " << allocated_process_size[process_id] << endl;
        allocated_process_size[process_id] = 0;
      }
      else {
        cout << "Process " << process_id << " is not running." << endl;
      }
    }

    // to exit or terminate the program;
    else {
      return 0;
    }

    cout << "Free Memory is: " << free_memory << endl << endl;
  }

  return 0;
}
