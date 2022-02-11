// First Come First Serve process scheduling algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // input section
  int n;
  cout << "Enter number of Process: ";
  cin >> n;
  int arrival_time[n + 1], burst_time[n + 1], waiting_time[n + 1], turn_around_time[n + 1];
  cout << "Enter arrival time of each process: " << endl;
  for(int i = 1; i <= n; i++) cin >> arrival_time[i];
  cout << "Enter burst time of each process: " << endl;
  for(int i = 1; i <= n; i++) cin >> burst_time[i];

  // calculation section
  waiting_time[1] = 0;
  turn_around_time[1] = burst_time[1];
  int total_waiting_time = 0, total_turn_around_time = turn_around_time[1];
  for(int i = 2; i <= n; i++) {
    waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1] - arrival_time[i];
    if(waiting_time[i] < 0) waiting_time[i] = 0;
    turn_around_time[i] = waiting_time[i] + burst_time[i];
    total_waiting_time += waiting_time[i];
    total_turn_around_time += turn_around_time[i];
  }

  float average_waiting_time = (float) total_waiting_time / n;
  float average_turn_around_time = (float) total_turn_around_time / n;

  // output section
  cout << endl << "Process No. " << "  Arrival Time  " << "  Burst Time   " << "  Waiting Time   " << "Turn Around Time" << endl;
  for(int i = 1; i <= n; i++) {
    cout << "     " << i;
    cout << "              " << arrival_time[i];
    cout << "              " << burst_time[i];
    cout << "              " << waiting_time[i];
    cout << "              " << turn_around_time[i] << endl;
  }

  cout << endl;
  cout << "Average Waiting Time: " << average_waiting_time << endl;
  cout << "Average Turn Around Time: " << average_turn_around_time << endl;

  return 0;
}


/*

3
0 0 0
10 5 8

*/
