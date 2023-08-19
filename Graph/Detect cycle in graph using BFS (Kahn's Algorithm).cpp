bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // kahn's algorithm to find whether there is cycle or not
        
        // find indegree
        vector <int> inDegree(V, 0);
        
        for(int i = 0; i<V; i++) {
            for(auto j : adj[i]) {
                inDegree[j]++;
            }
        }
        
        
        queue <int> q;
        // count of topological sorted elements
        int count = 0;
        for(int i = 0; i<V; i++) {
          // if there is zero inDegree then add it to the queue
            if(inDegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(auto i: adj[front]) {
              // reduce inDegree's of all its adj nodes
                inDegree[i]--;
                if(inDegree[i] == 0) {
                    q.push(i);
                    count++;
                }
            }
            
        }
        // if the count of all zero inDegree nodes equal to the total nodes, so we can sa that there is no cycle in the graph
        if(count == V) return 0;
        // Other wise there is cycle...
        return 1;
    }
