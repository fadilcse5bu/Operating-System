// CSCAN Disk Scheduling Algorithm towards the larger value

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;      // number of request
  int head;   // initial head
  int limit;  // cylinder size
  cin >> n >> head >> limit;
  int request[n], val = 0; // val = immediate lower value of head
  for(int i = 0; i < n; i++) {
    cin >> request[i];
    if(request[i] < head and request[i] > val) val = request[i];
  }

  int seek_time = (limit - head) + (limit - 0) + (val - 0);
  cout << "Total Seek Time: " << seek_time << endl;

  return 0;
}


/*
7 50
82 170 43 140 24 16 190
*/


