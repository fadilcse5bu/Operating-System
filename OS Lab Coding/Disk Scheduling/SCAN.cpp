// SCAN Disk Scheduling Algorithm towards the larger value

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;      // number of request
  int head;   // initial head
  int limit;  // cylinder size
  cin >> n >> head >> limit;
  int request[n], min_value = limit;
  for(int i = 0; i < n; i++) {
    cin >> request[i];
    min_value = min(min_value, request[i]);
  }

  if(min_value >= head) min_value = limit;
  int seek_time = (limit - head) + (limit - min_value);
  cout << "Total Seek Time: " << seek_time << endl;

  return 0;
}


/*
7 50
82 170 43 140 24 16 190
*/

