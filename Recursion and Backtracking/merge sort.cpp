#include <bits/stdc++.h>

using namespace std;

void merge(int *v, int left, int right) {
    int mid = left + (right - left)/2;
    // two new vectors length
    int len1 = (mid + 1) - left; // we have to include mid ele also in left vector
    int len2 = mid - right;
    
    // initialize new vectors with the new size_t
    int *first = new int[len1];
    int *second= new int[len2];
    
    // copy main vector's left to first and right to second vector respectively
    int mainVecIndex = left;
    for(int i = 0; i<len1; i++) {
        first[i] = v[mainVecIndex++];
    }
    
    mainVecIndex = mid+1;
    for(int i = 0; i<len2; i++) {
        second[i] = v[mainVecIndex++];
    }
    
    // merge two sorted vectors
    int index1 = 0, index2 = 0;
    mainVecIndex = left;
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2] ) {
            v[mainVecIndex++] = first[index1++];
        }
        else {
            v[mainVecIndex++] = second[index2++];
        }
    }
    
    // insert remaining element from any vector to main vector
    while(index1 < len1) {
        v[mainVecIndex++] = first[index1++];
    }
    
    while(index2 < len2) {
        v[mainVecIndex++] = second[index2++];
    }
}

void mergeSort(int *v, int left, int right) {
    // BASE CASE
    if(left >= right) return;
    
    int mid = left + (right - left)/2;
    
    // sort left vector
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    
    // merge both vectors
    merge(v, left, right);
}

int main()
{
    int n;
    cin >> n;
    int* v = new int[n];
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, n-1);
    return 0;
}
