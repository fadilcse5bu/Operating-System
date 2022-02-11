// Priority preemptive process scheduling algorithm
// This is similar to the Shortest Job First preemptive algorithm
// In SJF(preemptive) we select the arrived process as the burst time
// but now we select the arrived process as the priority value of this process
// here lowest priority value means the highest priority

#include <bits/stdc++.h>
using namespace std;

int main()
{
  //input section
  int n;
  cout << "Enter the number of Process:\n";
  cin >> n;

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
      if(arrival_time[i] <= current_time && priority[i] < mn && rt[i] > 0) {
        mn = priority[i];
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

7
2 6 3 5 4 10 9
0 1 2 3 4 5 6
1 7 3 6 5 15 8

7
2 6 3 5 7 4 10
0 2 1 4 6 5 7
3 5 4 2 9 4 10

5
3 4 9 7 8
0 1 3 2 4
3 6 1 2 4

*/





