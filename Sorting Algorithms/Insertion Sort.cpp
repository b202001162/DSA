
// start from index 1 and compare the current element to previous elements for it's right place

// Worst TC = O(N*N)
// BEST TC = O(N)
// SPACE COMPLEXITY O(1)

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i = 1; i<n; i++) {
        // we assume that first or 0th ele is already sorted
        // for round 1 to n-1
        for(int j = i-1; j>=0; j--) {
            // we check for current index's all previous elements
            if(arr[j] > arr[j+1]) {
                // when previous element is greater then the current ele then swap them
                swap(arr[j], arr[j+1]);
            } else {
              break;
            }
        }
    }
    return;
}
