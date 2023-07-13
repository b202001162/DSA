   
#include <bits/stdc++.h>
using namespace std;


void dfs(vector <pair<int, int>> adj[], vector <bool>&visited, vector <bool>&srcVisited, int src, stack <int> &ans) {
    visited[src] = 1;
    srcVisited[src] = 1;
    
    for(auto i: adj[src]) {
        if(!visited[i.first]) {
            dfs(adj, visited, srcVisited, i.first, ans);
        }
    }
    
    srcVisited[src] = 0;
    ans.push(src);
    return;
}

void shortestPathInDirectedGraph(vector<pair<int,pair<int,int>>> edges, int n, int src) {
    vector<pair<int, int>> adj[n];
    for(auto i: edges) {
        adj[i.first].push_back(i.second);
    }
    
    vector <bool> visited(n, 0);
    vector <bool> srcVisited(n, 0);
    // containing topological sort ordered of graph
    stack <int> topologicalSort;
    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            dfs(adj, visited, srcVisited, i, topologicalSort);
        }
    }
    
    vector <int> srcToNodeDistance(n, INT_MAX);
    srcToNodeDistance[src] = 0;
    for(int i = 0; i<n; i++) {
        int top = topologicalSort.top();
        topologicalSort.pop();
        if(srcToNodeDistance[top] == INT_MAX) continue;
        for(auto i: adj[top]) {
                srcToNodeDistance[i.first] = min(srcToNodeDistance[i.first], srcToNodeDistance[top]+i.second);
        }
    }
    
    
    for(auto i: srcToNodeDistance) {
        cout << i << " ";
    } cout << endl;
    
    
}




int main () {
    int n, m;
    n = 6, m = 9;
    vector <pair<int,pair<int,int>>> v(m);
    v[0] = {1, {3, 6}};
    v[1] = {1, {2, 2}};
    v[2] = {0, {1, 5}};
    v[3] = {0, {2, 3}};
    v[4] = {3, {4, -1}};
    v[5] = {2, {4, 4}};
    v[6] = {2, {5, 2}};
    v[7] = {2, {3, 7}};
    v[8] = {4, {5, -2}};
    
    int src;
    src = 1;
    
    shortestPathInDirectedGraph(v,n, src);
    return 0;
}
