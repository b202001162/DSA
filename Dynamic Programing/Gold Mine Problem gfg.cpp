class Solution{
public:
    int maxGold(int &n, int &m, int i, int j, vector <vector<int>> &dp, vector <vector <int>> &gold) {
        // base case
        if(!(i < n && i >= 0 && j < m && j>=0)) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int rightUp, right, rightDown;
        
        if(i-1 >= 0 && j+1 < m && dp[i-1][j+1] != -1) rightUp = dp[i-1][j+1];
        else rightUp= maxGold(n, m, i-1, j+1, dp, gold);
        
        if(j+1 < m && dp[i][j+1] != -1) right = dp[i][j+1];
        else right = maxGold(n, m, i, j+1, dp, gold);
        
        if(j+1 < m && i+1 < n && dp[i+1][j+1] != -1) rightDown = dp[i+1][j+1];
        else rightDown = maxGold(n, m, i+1, j+1, dp, gold);
        
        return dp[i][j] = gold[i][j] + max(max(rightUp, right), rightDown);
        
    }

    int maxGold(int n, int m, vector<vector<int>> gold)
    {
        // code here
        vector <vector <int>> dp (n, vector <int> (m, -1));
        
        int mx = INT_MIN;
        
        for(int i = 0; i<n; i++) {
            mx = max(maxGold(n, m, i, 0, dp, gold), mx);
        }
        return mx;
    }
};
