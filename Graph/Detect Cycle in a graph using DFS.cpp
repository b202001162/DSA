void dfs(vector <int> adj[], bool &ans, int &n, int &node, vector <bool> &visited, vector <bool> &pathVisited) {
        // base cases
        if(ans == 1) return;
        if(pathVisited[node] == 1) {
            ans = 1;
            return;
        }
        if(visited[node] == 1) return;
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto i : adj[node]) {
            dfs(adj, ans, n, i, visited, pathVisited);
        }
        
        // backtracking
        pathVisited[node] = 0;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool ans = 0;
        vector <bool> visited(V, 0), pathVisited(V, 0);
        // path vector will keep track of all nodes for the perticular path
      // for the other path the pathvector will be cleared
        for(int i = 0; i<V; i++) {
            if(ans == 1) break;
            dfs(adj, ans, V, i, visited, pathVisited);
        }
        return ans;
    }
