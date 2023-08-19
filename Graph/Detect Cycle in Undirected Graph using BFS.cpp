bool isCycle(int n, int node, vector <int> adj[]) {
        
        bool ans = 0;
        
        queue <pair <int, int>> q;
        vector <int> visited(n, 0);
        q.push({node, -1});
        visited[node] = 1;
        
        while(!q.empty()) {
            int newNode = q.front().first, parent = q.front(). second;
            q.pop();
            for(auto i : adj[newNode]) {
                if(i != parent && visited[i] == 0) {
                    // mark it visited and push it in to the queue
                    visited[i] = 1;
                    q.push({i, newNode});
                } else if(i == parent) { // if the adj node is parent then skip it
                    continue;
                } else if(visited[i] == 1) { // if adj node is not parent and aslo visited then there is cycle
                    return 1;
                } 
            }
        }
        
        
        return ans;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool ans = 0;
        
        for(int i= 0; i<V; i++) {
            // or operator
            ans |= isCycle(V, i, adj);
            
            if(ans == 1) return 1;
        }
        
        return ans;
    }
