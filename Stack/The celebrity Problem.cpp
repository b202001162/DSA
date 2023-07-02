class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack <int> st;
        for(int i = 0; i<n; i++) {
            st.push(i);
        }
        while(st.size() != 1) {
          // check which one is know to which one, and push the one who don't know
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if(M[t1][t2] == 1) {
                st.push(t2);
            }
            else st.push(t1);
        }
        bool flag = 1;
      // check all the other know the st.top() person
        for(int i = 0; i<n; i++) {
            // because M[i][i] always == 0
            if(i == st.top()) continue;
            if(M[i][st.top()] == 0) flag = 0;
        }
      // check all the element of the person is 0, it's means that he don't know anyone
        for(int i = 0; i<n; i++) {
            if(M[st.top()][i] == 1) flag = 0;
        }
        if(flag == 0) return -1;
        else return st.top();
    }
};
