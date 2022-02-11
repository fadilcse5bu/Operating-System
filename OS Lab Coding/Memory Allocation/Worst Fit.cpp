// Worst Fit Memory Allocation Algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int block;   // number of blocks
  cin >> block;
  int block_size[block + 1];
  for(int i = 1; i <= block; i++) {
    cin >> block_size[i];
  }

  int process;   // number of processes
  cin >> process;
  int process_size[process + 1], allocation[process + 1];
  for(int i = 1; i <= process; i++) {
    cin >> process_size[i];
    allocation[i] = -1;   // initially each process is not fit to any block
  }

  int internal_fragment = 0, is_free_block[block + 1] = {0};
  for(int i = 1; i <= process; i++) {
    int indx = -1;  // find index which block size is as maximum as possible and greater or equal to process size
    for(int j = 1; j <= block; j++) {
      if(is_free_block[j] == 0 and process_size[i] <= block_size[j]) {
        if(indx == -1) {
          indx = j;
        }
        else {
          if(block_size[j] > block_size[indx]) {
            indx = j;
          }
        }
      }
    }
    if(indx != -1) {
      allocation[i] = indx;
      is_free_block[indx] = 1;
      internal_fragment += (block_size[indx] - process_size[i]);
    }
  }

  int external_fragment = 0;
  for(int i = 1; i <= block; i++) {
    if(is_free_block[i] == 0) {
      external_fragment += block_size[i];
    }
  }

  //Print section
  cout << endl << endl;
  cout << "Process No. " << " Process Size  " << " Block No.  " << "   Block Size " << "  Internal Fragment" << endl;
  for(int i = 1; i <= process; i++) {
    cout << "     " << i << "           " << process_size[i];
    if(allocation[i] == -1) {
      cout << "      Not Allocated";
    }
    else {
      cout << "           " << allocation[i] << "        ";
      cout << "     " << block_size[allocation[i]] << "            ";
      cout << block_size[allocation[i]] - process_size[i];
    }
    cout << endl;
  }


  cout << endl;
  cout << "Total internal fragment: " << internal_fragment << endl;
  cout << "Total external fragment: " << external_fragment << endl;

  return 0;
}

/*
5
100 500 200 300 600
4
212 417 112 426
*/

/*
6
100 500 200 300 600 50
5
212 417 112 426 100
*/

