// You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
// Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.


// Approach: we traverse the array from the right side, initially we pushed -1 in the stack. 
//           Then we are gonna check, if (currentEle > st.top()) then we write it to the ans vector and move for next element.
//           OW we looking for the first smallest element in the stak, we're gonna poping all the ele until we would smallest ele (Probably -1) 
//           and then Push the current ele in both the cases.

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack <int> st;
    // push -1 as base element, which is always less than any element n the arr
    st.push(-1);
    vector <int> ans(n, 0);
    for(int i = n-1; i>=0; i--) {
        if(arr[i] > st.top()) {
            // if the top is smaller then move ahead
            ans[i] = st.top();
        }
        else {
            while(!st.empty()) {
                // fnd for the one which is smaller than the current one (likely -1)
                if(st.top() < arr[i]) {
                    ans[i] = st.top();
                    break;
                }
                // pop if the ele is greater than the current one
                st.pop();
            }
        }
        // push the ele in both cases
        st.push(arr[i]);
    }
    return ans;
}
