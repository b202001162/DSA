vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int src) {
    // Write your code here.
   // undirected graph
    vector <pair<int, int>> adj[n];
    for(auto i: vec) {
        adj[i[0]].push_back(make_pair(i[1],i[2]));
        adj[i[1]].push_back({i[0],i[2]});
    }
    // distance from the src node, initially infinite
    vector <int> srcToNodeDist(n, INT_MAX);
    srcToNodeDist[src] = 0;

  // choose every time minimum dist node
    set <pair<int, int>> minDistPairChooseFirst;
    
    minDistPairChooseFirst.insert({0, src});
    
    while(!minDistPairChooseFirst.empty()) {
        // always has minimum distance
        auto it = minDistPairChooseFirst.begin();
        pair <int, int> topPair = *it;
        minDistPairChooseFirst.erase(it);
        for(auto i : adj[topPair.second]) {
            if(srcToNodeDist[i.first] > topPair.first + i.second) {
                auto record = minDistPairChooseFirst.find({srcToNodeDist[i.first], i.first});
                if(record != minDistPairChooseFirst.end()) {
                    minDistPairChooseFirst.erase(record);
                }
                srcToNodeDist[i.first] = topPair.first + i.second;
                minDistPairChooseFirst.insert({srcToNodeDist[i.first], i.first});
            }
        }
    }
    
    return srcToNodeDist;
}
