

void dfs(unordered_map<int, unordered_set<int>>g, vector<bool>&visited, int node, vector <int>& temp){
    if(visited[node]) return;
    temp.push_back(node);
    visited[node] = 1;

    for(auto i: g[node]) {
        // travers all its adj nodes
        if(!visited[i]) {
            dfs(g, visited, i,temp);
        }
    }
    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    int n = edges.size();
    vector <vector <int>> ans;
    vector <bool> visited(V, 0);
    unordered_map <int, unordered_set<int>> graph;
    for(auto i : edges) {
        graph[i[0]].insert(i[1]);
        graph[i[1]].insert(i[0]);
    }

    for(int i = 0; i<graph.size(); i++) {
        if(!visited[i]) {
            vector <int> temp;
            dfs(graph, visited, i, temp);
            ans.push_back(temp);
        }
    
    }
    return ans;
}
