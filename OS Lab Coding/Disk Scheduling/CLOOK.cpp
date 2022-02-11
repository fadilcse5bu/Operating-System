// CLOOK Disk Scheduling Algorithm towards the larger value

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;      // number of request
  int head;   // initial head
  cin >> n >> head;

  int request[n], min_value = head, max_value = 0, val = 0; // val = immediate lower value of head
  for(int i = 0; i < n; i++) {
    cin >> request[i];
    min_value = min(min_value, request[i]);
    max_value = max(max_value, request[i]);
    if(request[i] < head and request[i] > val) val = request[i];
  }

  int seek_time = (max_value - head);
  if(min_value < head) {
    seek_time += ((max_value - min_value) + (val - min_value));
  }

  cout << "Total Seek Time: " << seek_time << endl;

  return 0;
}


/*
7 50
82 170 43 140 24 16 190
*/


