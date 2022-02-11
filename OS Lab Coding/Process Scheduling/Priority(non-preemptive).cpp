// Priority non-preemptive process scheduling algorithm
// This is similar to the Shortest Job First non-preemptive algorithm
// In SJF(non-preemptive) we select the arrived process as the burst time
// but now we select the arrived process as the priority value of this process
// here lowest priority value means the highest priority

#include <bits/stdc++.h>
using namespace std;

int main()
{
  //input section
  int n;
  cin >> n;   // number of process

  int priority[n + 1];
  cout << "Enter priority value of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> priority[i];
  }

  int arrival_time[n + 1];
  cout << "Enter arrival time of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> arrival_time[i];
  }

  int burst_time[n + 1];
  cout << "Enter burst time of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> burst_time[i];
  }

  // to calculate
  int waiting_time[n + 1], turn_around_time[n + 1];
  int current_time = 0, total_waiting_time = 0, total_turn_around_time = 0;
  int process_done[n + 1] = {0}; // to check whether the ith process is completed or not. Initially all processes are uncompleted

  for(int i = 1; i <= n; i++) {  // while all the processes are not completed
    int p_id = -1;
    for(int id = 1; id <= n; id++) {  // to find an arrived process whose priority value as minimum as possible
      if(process_done[id] == 0 and arrival_time[id] <= current_time) {
        if(p_id == -1) p_id = id;  // found the first one
        else {
          if(priority[id] < priority[p_id]) p_id = id;
        }
      }
    }

    if(p_id != -1) {  // found an arrived process
      waiting_time[p_id] = current_time - arrival_time[p_id];
      total_waiting_time += waiting_time[p_id];
      turn_around_time[p_id] = waiting_time[p_id] + burst_time[p_id];
      total_turn_around_time += turn_around_time[p_id];
      process_done[p_id] = 1;  // this process is completed
      current_time += burst_time[p_id];
    }
    else {
      // to find the nearest process whose priority value is as minimum as possible
      for(int id = 1; id <= n; id++) {
        if(process_done[id] == 0) {
          if(p_id == -1) p_id = id;
          else {
            if(priority[id] < priority[p_id]) p_id = id;
          }
        }
      }
      current_time = arrival_time[p_id];
      waiting_time[p_id] = current_time - arrival_time[p_id];
      total_waiting_time += waiting_time[p_id];
      turn_around_time[p_id] = waiting_time[p_id] + burst_time[p_id];
      total_turn_around_time += turn_around_time[p_id];
      current_time += burst_time[p_id];
      process_done[p_id] = 1;
    }
  }

  float average_waiting_time = (float) total_waiting_time / n;
  float average_turn_around_time = (float) total_turn_around_time / n;

  // output section
  cout << endl << "Process No. "  << "  Waiting Time   " << "Turn Around Time" << endl;
  for(int i = 1; i <= n; i++) {
    cout << "    P" << i;
    cout << "              " << waiting_time[i];
    cout << "              " << turn_around_time[i] << endl;
  }

  cout << endl;
  cout << "Average Waiting Time: " << average_waiting_time << endl;
  cout << "Average Turn Around Time: " << average_turn_around_time << endl;


  return 0;
}

/*

7
2 6 3 5 7 4 10
0 2 1 4 6 5 7
3 5 4 2 9 4 10

5
3 4 9 7 8
0 1 3 2 4
3 6 1 2 4

*/




