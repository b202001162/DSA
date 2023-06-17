// Best and Worst TC = O(N*N);
// After each i(th) round, we will place i(th) largest element to its right place (in sorted manner)
// Compare current ele to its next ele and if(current is bigger then swap them) OR leave as it is.

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i =0; i<n-1; i++) {
        // for round n - 1
        for(int j = 0; j<n-1; j++) {
            // for index 0 to n-1
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return;
}
