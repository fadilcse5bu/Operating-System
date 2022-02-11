// Optimal page replacement algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
  //input section
  int frame_size;
  cout << "Enter Frame Size: ";
  cin >> frame_size;
  int re;  // number of references
  cout << "Enter Number of Reference: ";
  cin >> re;
  int page_reference[re];
  cout << "Enter All Page References:" << endl;
  for(int i = 0; i < re; i++) {
    cin >> page_reference[i];
  }

  vector <int> slot;
  map <int, int> is_present;
  int total_hits = 0, total_faults = 0;
  for(int i = 0; i < re; i++) {
    if(is_present[page_reference[i]] == 1) {
      total_hits++;
      cout << "Hit occurred for page " << page_reference[i] << endl;
    }
    else {
      total_faults++;
      is_present[page_reference[i]] = 1;
      if(slot.size() < frame_size) {
        slot.push_back(page_reference[i]);
      }
      // to replace the page that won’t be utilized for the longest time frame.”
      else {
        map <int, int> nearest;
        for(int j = i + 1; j < re; j++) {
          if(nearest[page_reference[j]] == 0) nearest[page_reference[j]] = j;
        }

        int in = 0;
        for(int j = 0; j < slot.size(); j++) {
          if(nearest[slot[j]] == 0) {
            in = j;
            break;
          }
          else if(nearest[slot[j]] > nearest[slot[in]]) {
            in = j;
          }
        }
        is_present[slot[in]] = 0;
        slot[in] = page_reference[i];
      }
      cout << "Fault occurred for page " << page_reference[i] << endl;
    }

    cout << "Pages loaded in physical memory currently: ";
    for(int j = 0; j < slot.size(); j++) {
      cout << slot[j] << " ";
    }
    cout << endl << endl;
  }

  cout << endl << "Total Hits: " << total_hits << endl;
  cout << "Total Faults: " << total_faults << endl;

  return 0;
}

/*

3 7
1 3 0 3 5 6 3

4 14
7 0 1 2 0 3 0 4 2 3 0 3 2 3

3 20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

*/


