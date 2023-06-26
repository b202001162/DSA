#define mod (int)(1e9 + 7)
int nCr(int n, int r)
{
    if (n < r)
        return 0;

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
  
    prev[0] = 1;  // nC0 == 1
    curr[0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            curr[j] = (prev[j - 1] + 0LL + prev[j]) % mod;  // nCr (updated value) = (n-1)C(r-1) (means prev[j-1]) + (n-1)C(r) (means prev[j]);
        }
        prev = curr;  // Update previous vec to curr for next iteration
    }
    return curr[r];
}
