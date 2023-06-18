#include <bits/stdc++.h>
using namespace std;

int partition (vector <int> &v, int left, int right) {
  int pivot = v[left];
  
  int count = 0;
  for(int i = left+1; i<=right; i++) {
    // count # of eles which lesser than or equal to the pivot
    if(v[i] <= pivot) count++;
  }
  
  // correct possision for pivot ele
  int pivotIndex = left + count;
  // place the pivot to its correct possision
  swap(v[pivotIndex], v[left]);
  
  while(left < pivotIndex && right > pivotIndex) {
    while(v[left] <= pivot) {
      // find greater elements than pivot from left side
      left++;
    }
    
    while(v[right] > pivot) {
      // find lesser elements than pivot from right
      right--;
    }
    
    if(left < pivotIndex && right > pivotIndex) {
      swap(v[left], v[right]);
      left++;
      right--;
    }
  } 
  return pivotIndex;
}

void quickSort(vector <int>&v, int left, int right) {
  // BASE CASE
  if(left >= right) return;
  
  // Partition
  int p = partition(arr, left, right);
  
  // sort the left and right part
  quickSort(arr, left, p-1);
  quickSort(arr, p+1, right);  
  return;
}

void main () {
  int n;
  cin >> n;
  vector <int> v(n);
  for(int i = 0; i<n; i++) {
    cin >> v[n];
  }
  quickSort(v, 0, n-1);
  for(int i = 0; i<n; i++) {
    cout << v[n] <<  " ";
  } cout << endl;
  return;
}
