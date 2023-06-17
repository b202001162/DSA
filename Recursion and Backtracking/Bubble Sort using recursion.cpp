// Online C++ compiler to run C++ program online
// O(N*N)
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector <int> &v, int size) {
    if(size == 0 || size == 1 ) return;
    for(int i = 0; i<size-1; i++) {
        if(v[i] > v[i+1]) swap(v[i], v[i+1]);
    }
    bubbleSort(v, size-1);
}

int main() {
    vector <int> v;
    int n;
    cin >> n;
    v = vector <int> (n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    bubbleSort(v, v.size());
    for(auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
