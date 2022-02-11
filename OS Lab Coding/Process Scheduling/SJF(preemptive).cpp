// Shortest Job First preemptive process scheduling algorithm
// Time complexity = (sum of all burst time * n) where n is number of process

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
  int rt[n + 1];  // remaining burst time
  cout << "Enter burst time of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> burst_time[i];
    rt[i] = burst_time[i];  // initially copy burst time as remaining time
  }

  int waiting_time[n + 1], turn_around_time[n + 1], total_waiting_time = 0, total_turn_around_time = 0;
  int complete_process = 0, mn = INT_MAX, p_id, current_time = 0, ck = 0;
  int process_done[n + 1] = {0}; // to check whether the ith process is completed or not. Initially all processes are uncompleted

  // to calculate
  while(complete_process != n) { // to traverse until all process gets completely executed
    for(int i = 1; i <= n; i++) { // to find process with minimum remaining time at every current time
      if(arrival_time[i] <= current_time && rt[i] < mn && rt[i] > 0) {
        mn = rt[i];
        p_id = i; // process id
        ck = 1;
      }
    }
    ++current_time;
    if(ck == 0) continue;  // it means the remaining time of current process is minimum

    rt[p_id]--;  // to reduce remaining time by 1 of this process(p_id)
    mn = rt[p_id];

    if(rt[p_id] == 0) {
      ck = 0;
      mn = INT_MAX;
      complete_process++; // this process gets completely executed
      waiting_time[p_id] = current_time - arrival_time[p_id] - burst_time[p_id];
      turn_around_time[p_id] = waiting_time[p_id] + burst_time[p_id];

      total_waiting_time += waiting_time[p_id];
      total_turn_around_time += turn_around_time[p_id];
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
1 1 2 3
6 8 7 3

4
3 0 4 5
5 4 2 4

4
2 0 4 5
3 4 2 4

5
2 5 1 0 4
6 2 8 3 4

*/




