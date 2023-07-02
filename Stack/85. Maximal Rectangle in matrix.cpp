class Solution {
public:

    int largestRectangleArea(vector<int> v) {
        // v represents the height vector
        int area = 0;
        int n = v.size();
        stack <int> st;
        st.push(-1);
        for(int i = 0; i<n; i++) {
            while(st.size() > 1 && v[st.top()] >= v[i]) {
                int top = st.top();
                // int start;
                st.pop();
                // start = st.top();
                area = max(area, v[top]* (i - st.top() - 1));
            }
            st.push(i);
        }

        while (st.size() > 1) {
            int top = st.top();
            st.pop();
            // int start = st.top();
            area = max(area, v[top]*(n-st.top()-1));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0;
        vector <int> toBeSent(matrix[0].size(), 0);
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == '0') toBeSent[j] = 0;
                else {
                    toBeSent[j] += 1;
                }
            }
            area = max(largestRectangleArea(toBeSent), area);
        }
        return area;
    }
};



class Solution {
public:
    // find array of next smaller element by traversing the array from the right or Back
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
    // find the array of previous smaller eles by traversing the array from the left or front
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

    int largestRectangleArea(vector<int> v) {
        // v represents the height vector
        int area = 0;
        int n = v.size();
        vector <int> next = nextSmallerEles(v, n);
        vector <int> prev = prevSmallerEles(v, n);

        // get the area l * b;
        for(int i = 0; i<n; i++) {
            // this case triggered when all eles are equal
            if(next[i] == -1) {
                next[i] = n;
            }
            // here L is v[i] which is height and R is the distance between the next smaller ele and privous smaller element index's
            area = max(area, v[i] * (next[i] - prev[i] - 1));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0;
        vector <int> toBeSent(matrix[0].size(), 0);
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[i].size(); j++) {
                // take one by one row as base if(ele from the currrent row is zero then the entire column of the particular element is Zero's eight)
                if(matrix[i][j] == '0') toBeSent[j] = 0;
                else {
                    // height of the bar by adding the base elements to previous valid elements
                    toBeSent[j] += 1;
                }
            }
            area = max(largestRectangleArea(toBeSent), area);
        }
        return area;
    }
};
