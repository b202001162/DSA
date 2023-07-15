#include <bits/stdc++.h>
using namespace std;

void levelOrderedTraversal(vector <vector <long long>> edges, int n) {
    // this function for 1 index based vector
    vector <long long> adj[n+1];
    for(auto i: edges) {
        adj[i[0]].push_back(i[1]);
    }
    
    queue <long long>q;
    // 1 is always rooted element
    q.push(1);
    // its indecates that now the level is over and next is nodes are from new level
    q.push(-1);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        if(front == -1) {
            cout << endl;
            // push -1 for ensure the level is over
            if(!q.empty()) q.push(-1);
        } else {
            cout << front << " ";
            for(auto i : adj[front]) {
                q.push(i);
            }
        }
    }
    
    cout << endl;
    return;
}
 
 
 
 
int main () {
    long long n;
    cin >> n;
    
    vector <vector<long long>> edges(n-1, vector <long long>(2));
    for(long i = 0; i<n-1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    levelOrderedTraversal(edges, n);
    
    return 0;
}
