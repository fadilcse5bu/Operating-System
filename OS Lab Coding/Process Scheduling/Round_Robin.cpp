// Round Robin Process Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // input section
  int n;
  cout << "Enter the number of Process:\n";
  cin >> n;

  int arrival_time[n + 1];
  vector <pair<int, int>> sorted_arrival_time;
  cout << "Enter arrival time of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> arrival_time[i];
    sorted_arrival_time.push_back({arrival_time[i], i});
  }

  int burst_time[n + 1], remaining_burst_time[n + 1];
  cout << "Enter burst time of each process:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> burst_time[i];
    remaining_burst_time[i] = burst_time[i];
  }
  int time_quantum;
  cout << "Enter time quantum of the system:\n";
  cin >> time_quantum;


  sort(sorted_arrival_time.rbegin(), sorted_arrival_time.rend());  // descending or decreasing order
  queue <int> ready_queue;
  int current_time = -1, process_finished = 0;
  int waiting_time[n + 1], turn_around_time[n + 1];
  int total_waiting_time = 0, total_turn_around_time = 0;

  // to calculate
  while(process_finished < n) {
    int p_id = -1;
    if(ready_queue.empty()) {
      current_time++;  // at the first time current time will increase from -1 to 0
    }
    else {
      p_id = ready_queue.front();
      ready_queue.pop();
      if(remaining_burst_time[p_id] <= time_quantum) { // this is the last execution
        process_finished++;
        current_time += remaining_burst_time[p_id];
        remaining_burst_time[p_id] = 0;

        waiting_time[p_id] = current_time - arrival_time[p_id] - burst_time[p_id];
        turn_around_time[p_id] = waiting_time[p_id] + burst_time[p_id];

        total_waiting_time += waiting_time[p_id];
        total_turn_around_time += turn_around_time[p_id];
      }
      else {
        current_time += time_quantum;
        remaining_burst_time[p_id] -= time_quantum;
      }
    }

    while(sorted_arrival_time.size() > 0) {
      int indx = sorted_arrival_time.size() - 1;
      if(sorted_arrival_time[indx].first <= current_time) {
        ready_queue.push(sorted_arrival_time[indx].second);
        sorted_arrival_time.pop_back();  // to delete last element of the vector
      }
      else break;
    }

    if(p_id != -1 && remaining_burst_time[p_id] > 0) ready_queue.push(p_id);
    // p_id = -1 means that the ready queue is empty and we just increased the current time
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

6
0 1 2 3 4 6
5 6 3 1 5 4
4

5
0 1 2 3 4
5 3 1 2 3
2

3
0 0 0
10 5 8
2

*/

