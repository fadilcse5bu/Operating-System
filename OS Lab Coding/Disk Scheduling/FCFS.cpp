// First Come First Serve Disk Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; // number of request
  int head; // initial head
  cin >> n >> head;
  int request[n];
  for(int i = 0; i < n; i++) cin >> request[i];
  int seek_time = 0;

  for(int i = 0; i < n; i++) {
    seek_time += abs(head - request[i]);
    head = request[i];
  }

  cout << "Total Seek Time: " << seek_time << endl;


  return 0;
}


/*
7 50
82 170 43 140 24 16 190
*/
