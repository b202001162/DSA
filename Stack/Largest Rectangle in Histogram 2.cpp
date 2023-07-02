class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        // v represents the height vector
        int area = 0;
        int n = v.size();
        stack <int> st;
        st.push(-1);
        for(int i = 0; i<n; i++) {
            while(st.size() > 1 && v[st.top()] >= v[i]) {
                int top = st.top();
                st.pop();
                area = max(area, v[top]*(i - st.top() - 1));
            }
            st.push(i);
        }
        while(st.size() > 1) {
            int top = st.top();
            st.pop();
            area = max(v[top]*(n-st.top()-1), area);
        }
        return area;
    }
};
