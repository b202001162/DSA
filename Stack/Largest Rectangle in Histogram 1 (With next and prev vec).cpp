class Solution {
public:

    vector <int> nextSmallerEles(vector<int>v, int n) {
        stack <int> st;
        st.push(-1);
        vector <int> ans (n, 0);
        for(int i = n-1; i>=0; i--) {
            while(st.size() > 1 && v[st.top()] >= v[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector <int> prevSmallerEles(vector<int>v, int n) {
        stack <int> st;
        st.push(-1);
        vector <int> ans (n, 0);
        for(int i = 0; i<n; i++) {
            while(st.size() > 1 && v[st.top()] >= v[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& v) {
        // v represents the height vector
        int area = 0;
        int n = v.size();
        vector <int> next = nextSmallerEles(v, n);
        vector <int> prev = prevSmallerEles(v, n);

        for(int i = 0; i<n; i++) {
            if(next[i] == -1) {
                next[i] = n;
            }
            area = max(area, v[i] * (next[i] - prev[i] - 1));
        }
        return area;
    }
};
