#include <bits/stdc++.h>
using namespace std;

void dfs(vector <long long> adj[], long long node, long long n, vector <long long> weight, vector <bool> &visited, unordered_set <long long> &st, long long &ans) {
    // base cases
    if(node > n) return;
  // checks wether the weight is exist in the set or not
    if(st.find(weight[node-1]) != st.end()) return;
    if(visited[node]) return;
    ans++;
    visited[node] = 1;
    st.insert(weight[node-1]);
    
    for(auto i : adj[node]) {
      // traverse all its adjcancent nodes
        dfs(adj, i, n, weight, visited, st, ans);
    }
    // back track
    st.erase(weight[node-1]);
    return;
}


void findUniquePaths(vector <long long> weight, vector <vector <long long>> edges, long long n) {
    vector <long long> adj[n+1];
  // undirected graph and making spanning tree
    for(auto i: edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    
    vector <bool> visited(n+1, false);
  // for detecting the unique weight over paths 
    unordered_set <long long> st;
    
    long long ans = 0;
    dfs(adj, 1, n, weight, visited, st, ans);
    
    cout << ans << endl;
    return;
    
}

int main () {
  return 0;
}
