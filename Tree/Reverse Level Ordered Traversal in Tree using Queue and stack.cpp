#include <bits/stdc+.h>
using namespace std;

void reverseLevelOrderedTraversal(vector <vector <long long>> &edges, int n) {
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
    stack <vector <int>> ans;
    vector <int> temp;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        if(front == -1) {
            // cout << << endl;
            ans.push(temp);
            temp.clear();
            
            // push -1 for ensure the level is over
            if(!q.empty()) q.push(-1);
        } else {
            // cout << front << " ";
            temp.push_back(front);
            for(auto i : adj[front]) {
                q.push(i);
            }
        }
    }
    temp.clear();
  
    while(!ans.empty()) {
        temp = ans.top();
        st.pop();
        for(auto j:temp) {
            cout << j << " ";
        } cout << endl;
    }
    return;
}
