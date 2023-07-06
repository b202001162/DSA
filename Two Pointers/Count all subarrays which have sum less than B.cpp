int Solution::solve(vector<int> &A, int B) {
    int n=A.size(),count=0,sum=0,j=0;

    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        // run loop until the sum become less than B
        while(sum>=B)
        {
            sum-=A[j];
            j++;
        }
        count+=i-j+1;
    }
    return count;
}
