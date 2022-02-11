// First In First Out page replacement algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int frame_size;
  cout << "Enter Frame Size: ";
  cin >> frame_size;
  int re;  // number of references
  cout << "Enter Number of Reference: ";
  cin >> re;

  queue <int> slot;
  map <int, int> is_present;

  int total_hits = 0, total_faults = 0;
  cout << "Enter All References:" << endl;
  for(int i = 1; i <= re; i++) {
    int page_reference;
    cin >> page_reference;
    cout << endl;

    if(is_present[page_reference] == 1) {
      total_hits++;
      cout << "Hit occurred for page " << page_reference << endl;
    }
    else {
      total_faults++;
      is_present[page_reference] = 1;
      if(slot.size() < frame_size) {
        slot.push(page_reference);
      }
      else {
        int x = slot.front();
        slot.pop();
        slot.push(page_reference);
        is_present[x] = 0;
      }
      cout << "Fault occurred for page " << page_reference << endl;
    }

    cout << "Pages loaded in physical memory currently: ";
    int ct = 0, len = slot.size();
    while(ct < len) {
      int x = slot.front();
      slot.pop();
      slot.push(x);
      cout << x << " ";
      ++ct;
    }
    cout << endl << endl;
  }

  cout << endl << "Total Hits: " << total_hits << endl;
  cout << "Total Faults: " << total_faults << endl;

  return 0;
}

// Enter each value one by one to better understand
/*

3 7
1 3 0 3 5 6 3

4 14
7 0 1 2 0 3 0 4 2 3 0 3 2 3

3 20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

*/




