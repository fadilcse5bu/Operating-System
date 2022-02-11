// Shortest Seek Time First Disk Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; // number of request
  int head; // initial head
  cin >> n >> head;
  int request[n];
  for(int i = 0; i < n; i++) cin >> request[i];

  sort(request, request + n);
  queue <int> less_than_head, greater_than_head;
  for(int i = n - 1; i >= 0; i--) {
    if(request[i] <= head) {
      less_than_head.push(request[i]);
    }
  }
  for(int i = 0; i < n; i++) {
    if(request[i] > head) {
      greater_than_head.push(request[i]);
    }
  }

  int seek_time = 0;
  // calculate total seek time
  while(!less_than_head.empty() or !greater_than_head.empty()) {
    if(less_than_head.empty()) {
      int x = greater_than_head.front();
      seek_time += abs(head - x);
      greater_than_head.pop();
      head = x;
    }
    else if(greater_than_head.empty()) {
      int x = less_than_head.front();
      seek_time += abs(head - x);
      less_than_head.pop();
      head = x;
    }
    else {
      int x = less_than_head.front();
      int y = greater_than_head.front();
      if(abs(x - head) <= abs(y - head)) {
        seek_time += abs(x - head);
        head = x;
        less_than_head.pop();
      }
      else {
        seek_time += abs(y - head);
        head = y;
        greater_than_head.pop();
      }
    }
  }

  cout << "Total Seek Time: " << seek_time << endl;

  return 0;
}

/*
7 50
82 170 43 140 24 16 190
*/

