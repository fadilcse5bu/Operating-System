// Shortest Job First non-preemptive process scheduling algorithm
// Time complexity = (n * n) where n is number of process
// It can be solved within n*log(n) using priority queue and sorting arrival time

#include <bits/stdc++.h>
using namespace std;

int main()
{
  //input section
  int n;
  cin >> n;   // number of process

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
    for(int id = 1; id <= n; id++) {  // to find an arrived process of minimum burst time
      if(process_done[id] == 0 and arrival_time[id] <= current_time) {
        if(p_id == -1) p_id = id; // found the first one
        else {
          if(burst_time[id] < burst_time[p_id]) p_id = id;
        }
      }
    }

    if(p_id != -1) {  // found an arrived process of minimum burst time
      waiting_time[p_id] = current_time - arrival_time[p_id];
      total_waiting_time += waiting_time[p_id];
      turn_around_time[p_id] = waiting_time[p_id] + burst_time[p_id];
      total_turn_around_time += turn_around_time[p_id];
      process_done[p_id] = 1;  // this process is completed
      current_time += burst_time[p_id];
    }
    else {
      // to find the nearest process whose arrival time is as minimum as others
      for(int id = 1; id <= n; id++) {
        if(process_done[id] == 0) {
          if(p_id == -1) p_id = id;
          else {
            if(arrival_time[id] < arrival_time[p_id]) p_id = id;
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

4
3 0 4 5
5 4 2 4

4
2 0 4 5
3 4 2 4

*/



