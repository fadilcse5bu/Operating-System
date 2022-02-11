#include <bits/stdc++.h>
using namespace std;

int main()
{
  int pr;  // number of processes
  cout << "Enter number of process:\n";
  cin >> pr;
  int re;  // number of resources type
  cout << "Enter number of resources type:\n";
  cin >> re;

  int alloc[pr][re]; // allocated resources for every process of every resource type
  int mx[pr][re];    // maximum resources needed for every process of every resource type
  int avail[re];     // available resources right now

  queue <int> rp;    // remaining processes

  cout << "Enter allocated resources of every resource type:\n";
  for(int i = 0; i < pr; i++) {
    rp.push(i);
    for(int j = 0; j < re; j++) {
      cin >> alloc[i][j];
    }
  }

  cout << "Enter maximum resources needed for every process of every resource type:\n";
  for(int i = 0; i < pr; i++) {
    for(int j = 0; j < re; j++) {
      cin >> mx[i][j];
    }
  }

  cout << "Enter available resource for every process:\n";
  for(int i = 0; i < re; i++) {
    cin >> avail[i];
  }

  vector <int> safe_sequence;
  int ct = 0;
  // to find which processes are executable
  while(!rp.empty() and ct <= rp.size()) {
    ++ct;
    int x = rp.front(), flag = 0;
    rp.pop();
    for(int i = 0; i < re; i++) {
      if(mx[x][i] - alloc[x][i] > avail[i]) {
        flag = 1;
        break;
      }
    }

    if(flag == 0) {
      ct = 0;
      for(int i = 0; i < re; i++) {
        avail[i] += alloc[x][i];
      }
      safe_sequence.push_back(x);
    }
    else rp.push(x);
  }

  // to check if the system is safe or not
  if(safe_sequence.size() < pr) {
    cout << "the system is not safe" << endl;
  }
  else {
    cout << "the safe sequence is:" << endl;
    for(int i = 0; i < safe_sequence.size(); i++) {
      cout << "P" << safe_sequence[i];
      if(i != safe_sequence.size() - 1) cout << " --> ";
    }
  }
  cout << endl;


  return 0;
}

/*

5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2

*/
