bool isCycle(int n, int node, int parent, vector <int> adj[], vector <bool> &visited) {
        
        bool ans = 0;
        for(auto i : adj[node]) {
          // it I is it's parent then skip the iteration
            if(i == parent) continue;
          // if I is visited and not its parent then, return there is cycle
            if(visited[i] == 1) return true;
          // OW mark it as visited
            visited[i] = 1;
          // call dfs for I node
            ans |= isCycle(n, i, node, adj, visited);
        }
        
        return ans;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // lets crack it using DFS
        vector <bool> visited;
        // visited[0] = 1;
        bool ans = 0;
      // iterate all the nodes, because 0 is always in a connected to all the nodes, some time 0 is not connected to any node
        for(int i = 0; i<V; i++) {
            if(ans == 1) return 1;
            visited = vector <bool> (V, 0);
            visited[i] = 1;
            ans |= isCycle(V, i, -1, adj, visited);
        }
        return ans;
    }
