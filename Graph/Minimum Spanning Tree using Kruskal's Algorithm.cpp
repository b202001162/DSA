
#include <bits/stdc++.h>


int findParent(vector <int>&parent, int node) {
  if(parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}


// for merging trees

void unionSet(vector <int>&parent, vector <int>&rank, int u, int v) {
   u = findParent(parent, u);
   v = findParent(parent, v);

   if(rank[u] < rank[v]) {
     parent[u] = v;
   } else if(rank[u] > rank[v]) {
     parent[v] = u;
   } else {
     parent[u] = v;
     rank[v]++;
   }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

  // initailly all nodes' rank will be zero
  vector <int> parent(n), rank(n, 0);

  // all nodes' parents will be themselves
  for(int i = 0; i<n; i++) {
    parent[i] = i;
  }

  // sort by weight and take edge with has minium weight
  set <pair<int,pair<int, int>>> adj;
  for(auto i : edges) {
    adj.insert({i[2], {i[0], i[1]}});
  }

  int ans = 0;

  for(auto i : adj) {
    // if both the nodes have same parents then, it means they are already connected, so we don't have to go further
    if(findParent(parent,i.second.first) == findParent(parent,i.second.second)) continue;
    unionSet(parent, rank, i.second.first, i.second.second);
    // if we connects any nodes, then add its weight to the ans
    ans += i.first;
  }


  return ans;

}
