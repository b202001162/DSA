// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

// Example 1:

// Input:
// L = 6, N = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output: 1
// Explanation: (2, 80) have difference of 78.

bool findPair(int arr[], int size, int k){
    //code
    sort(arr, arr+size);  // O(N*log(N))
    for(int i = 0; i<size; i++) {  // O(N*log(N))
        int l = i+1, r = size - 1, mid = l + (r - l)/2;
        while(l <= r) { // (Binary search O(logN))
            if(arr[mid] - arr[i] == k) return 1;
            if(arr[mid] - arr[i] < k) {
                l = mid+1;
            }
            else r = mid - 1;
            mid = l + (r - l)/2;
        }
    }
    return 0;
}
