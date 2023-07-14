#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector <pair<int, int>> adj[n+1];
    for(auto i: g) {
        adj[i.first.first].push_back({i.first.second, i.second});
        adj[i.first.second].push_back({i.first.first, i.second});
    }

    // for tracking minimum cost of the node
    vector <int> key(n+1, INT_MAX);
    // for tracking nodes
    vector <bool> visited(n+1, false);
    // for stpring parents of perticular node
    vector <int> parent(n+1, -1);

    // take ZEROth node as src and start from it
    // int src = 0;
    parent[1] = -1;
    key[1] = 0;
    visited[1] = 1;

    for(auto i : adj[1]) {
        if(key[i.first] > i.second) {
            key[i.first] = i.second;
            parent[i.first] = 1;
        }
    }

    for(int k = 1; k<n; k++) {
        // src and 
        int src, min =INT_MAX;

        // find a node, which has min value and yet not visited
        for(int j = 1; j<=n; j++) {
            if(min > key[j] && visited[j]==0) {
                src = j;
                min = key[j];
            }
        }

        // mark it visited
        visited[src] = 1;

        // traverse its all adjcancy nodes and update if possible
        for(auto i: adj[src]) {
            // update its weight if it's old weight is greater than new and it's not visited yet
            if(key[i.first] > i.second and visited[i.first] == false) {
                // update key and then parent
                key[i.first] = i.second;
                parent[i.first] = src;
            }
        }

    }

    // for(int i = 1; i<=n; i++) {
    //     cout << i << " " << parent[i] << " ";
    // } cout << endl;

    // for(int i = 1; i<=n; i++) cout << i << " " << key[i] << " ";
    // cout << endl;
    vector <pair<pair<int,int>, int>> ans;
    set <pair<pair<int,int>,int>> st;

    for(int i = 2; i<=n; i++) {
        // if(parent[i] == -1) continue;
        st.insert({{parent[i],i}, key[i]});
    }

    for(auto i:st) {
        ans.push_back(i);
    }

    return ans;
}
