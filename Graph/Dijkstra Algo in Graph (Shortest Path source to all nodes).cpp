vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector <int> distance(V, INT_MAX);
      // cloud is where all nodes are all set (get shortest path)
        vector <bool> cloud(V, 0);
      // pair of <weight, node index>
        priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> q;
        distance[S] = 0;
        q.push({0, S});
        
        while(!q.empty()) {
            int front = q.top().second, weight = q.top().first;
            q.pop();
            cloud[front] = 1;
            
            for(auto i : adj[front]) {
                if(cloud[i[0]] == 0) {
                    int temp = distance[i[0]];
                    distance[i[0]] = min(distance[i[0]], i[1] + distance[front]);
                    // if pair already exist in the pq then don't add again
                    if(temp != distance[i[0]])
                    q.push({distance[i[0]], i[0]});
                }
            }
          
        }
        return distance;
    }
