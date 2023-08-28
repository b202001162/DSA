// initialize dp
vector <vector <int>> dp;
    Solution () {
      // assign all ele to -1
        dp = vector <vector <int>> (1001, vector <int> (1001, -1));
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // base case
       if(w == 0 || n == 0) return 0;
       // if already calculated
       if(dp[n][w] != -1) return dp[w][n];
       // when current weight is bigger than left weight no need to carry this just pass away
       if(wt[n-1] > w) {
           return dp[n][w] = knapSack(w, wt, val, n-1);
       }

      // max of take it and don't take it
       return dp[n][w] = max(knapSack(w, wt, val, n-1), val[n-1] + knapSack(w-wt[n-1], wt, val, n-1));
    }
