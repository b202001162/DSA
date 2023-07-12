#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector <int> adj[v];
  // how many edges comein 
    vector <int> outEdges(v, 0);
    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        outEdges[edge[1]]++;
    }
    queue <int> q;
    vector <int> ans;
    for(int i = 0; i<v; i++) {
        if(outEdges[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for(auto i: adj[front]) {
            if(--outEdges[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans;
}
