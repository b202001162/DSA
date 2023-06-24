class Solution{
    private:
    void ratInMaze(int i, int j, vector<vector<int>> nums, vector <vector <bool>> &visited, string output, vector <string> &ans, int n) {
        // base case
        if(i == n-1 && j == n-1) {
            ans.push_back(output);
            return;
        }
        
        for(int k = 0; k<4; k++) {
            switch(k) {
                case 0:
                    // down (i + 1, j)
                    if(i+1 < n && i+1 >= 0 && visited[i+1][j] == 0 && nums[i+1][j] == 1) {
                        visited[i+1][j] = 1;
                        output.push_back('D');
                        ratInMaze(i+1, j, nums, visited, output, ans, n);
                        output.pop_back();
                        visited[i+1][j] = 0;
                    }
                    break;
                    
                case 1:
                    // up (i - 1, j)
                    if(i-1 < n && i-1 >= 0 && visited[i-1][j] == 0 && nums[i-1][j] == 1) {
                        visited[i-1][j] = 1;
                        output.push_back('U');
                        ratInMaze(i-1, j, nums, visited, output, ans, n);
                        output.pop_back();
                        visited[i-1][j] = 0;
                    }
                    break;
                    
                case 2:
                    // left (i, j - 1)
                    if(j - 1 < n && j-1 >= 0 && visited[i][j-1] == 0 && nums[i][j-1] == 1) {
                        visited[i][j-1] = 1;
                        output.push_back('L');
                        ratInMaze(i, j-1, nums, visited, output, ans, n);
                        output.pop_back();
                        visited[i][j-1] = 0;
                    }
                    break;
                    
                case 3:
                    // right (i, j+1)
                    if(j+1 < n && j+1 >= 0 && visited[i][j+1] == 0 && nums[i][j+1] == 1) {
                        // mark visited and push it into the output
                        visited[i][j+1] = 1;
                        output.push_back('R');
                        
                        //recursive call
                        ratInMaze(i, j+1, nums, visited, output, ans, n);
                        
                        // Back track
                        output.pop_back();
                        visited[i][j+1] = 0;
                    }
                    break;
            }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &nums, int n) {
        // Your code goes here
        vector <string> ans;
        // if initial point or ending point or both are 0 then the output will be -1 or empty vector of string
        if(nums[0][0] == 0 || nums[n-1][n-1] == 0) return ans;
        // visited vec
        vector <vector <bool>> visited(n, vector <bool> (n,0));
        // mark initial position to 0
        visited[0][0] = 1;
        ratInMaze(0, 0, nums, visited, "", ans, n);
        return ans;
    }
};
