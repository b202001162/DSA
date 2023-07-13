vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

  //BFS always take shortest path, so we just have to traverse it, at the end we'll get the vector of ans (reverse of the path)
	vector <int> adj[n+1];
	for(auto i: edges) {
		adj[i.first].push_back(i.second);
	}
	vector <bool> visited(n+1, 0);
	vector <int> parent(n+1, -1);
	queue <int> q;
	visited[1] = 1;
	q.push(1);
	while(!q.empty()) {
		int front = q.front();
		q.pop();

		for(auto i: adj[front]) {
			if(!visited[i]) {
				q.push(i);
				parent[i] = front;
				visited[i] = 1;
			}
		}
	}

	// for(auto i : parent) {
	// 	cout << i << " ";
	// }
	// cout << endl;


	vector <int> ans;
	int index = t;
	ans.push_back(t);
	while(index != s && index > 0) {
		index = parent[index];
		ans.push_back(index);
		// if(index != -1)
		
	}

	// for(auto i: ans) cout << i << " ";
	// cout << endl;

	reverse(ans.begin(), ans.end());

	return ans;
	
}
