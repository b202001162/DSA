class Solution {
  public:
    // Function to find the number of islands.
    int n, m;
    
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, vector <pair<int, int>> &dir) {
        if(!(i >= 0 && i<n && j >= 0 && j < m && visited[i][j] == 0 )) {
            return;
        }
        
        visited[i][j] = 1;
        if(grid[i][j] == '0') return;
        
        for(int k = 0; k<8; k++) {
            dfs(i+dir[k].first, j+dir[k].second, visited, grid, dir);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector <pair<int, int>> dir = { {0,1}, {1,0}, {1,1}, {0,-1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        vector <vector<bool>> visited(n, vector<bool> (m, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                    dfs(i, j, visited, grid, dir);
                    ans++;
                }
            }
        }
        return ans;
    }
};
