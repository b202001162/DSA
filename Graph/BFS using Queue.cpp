#include <bits/stdc++.h> 

void bfs(unordered_map <int, set <int>> &g, vector <int>&ans, vector <bool> &visited, int node) {
    if(visited[node] == 1) return;
    queue <int> q;
    q.push(node);
    visited[node] = 1;


    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: g[frontNode]) {
            // iterates all its adj nodes if they are not visited
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    
    return;
}

vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    // Write your code here
    vector <int> ans;
    vector <bool> visited(v, 0);
    int n = edges.size();
    unordered_map <int, set <int>> graph;
    for(int i = 0; i<n; i++) {
        // create mapping
        graph[edges[i].first].insert(edges[i].second);
        graph[edges[i].second].insert(edges[i].first);
    }
    for(int i= 0; i<v; i++) {
        if(visited[i] == 0) {
            // ans.push_back(i);
            bfs(graph, ans, visited, i);
        }
    }
    return ans;
}
