// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector <int> &v, int size) {
    if(size == 0 || size == 1 ) return;
    for(int i = 0; i<size-1; i++) {
        if(v[i] > v[i+1]) swap(v[i], v[i+1]);
    }
    bubbleSort(v, size-1);
}

void insertionSort(vector <int> &v, int index) {
    // BASE CASE
    if(index == v.size()) return;
    for(int i = index-1; i >= 0; i--) {
        if(v[i] > v[i+1]) {
            swap(v[i], v[i+1]);
        }
    }
    insertionSort(v, index+1);
}

void selectionSort(vector <int> &v, int index) {
    if(index == v.size()) return;
    int minIndex = index;
    for(int i = index+1; i<v.size(); i++) {
        if(v[minIndex] > v[i]) {
            minIndex = i;
        }
    }
    swap(v[minIndex], v[index]);
    selectionSort(v, index+1);
}

int main() {
    vector <int> v;
    int n;
    cin >> n;
    v = vector <int> (n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    selectionSort(v, 1);
    for(auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
