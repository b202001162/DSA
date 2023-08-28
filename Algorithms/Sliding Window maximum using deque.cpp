vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque <int> dq;
        vector <int> ans;
        // first traverse k elements
        for(int i = 0; i<k; i++) {
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                // we'll pop_back elements until the last ele of dq is greater or eq to the current ele
                // that is means, we'll keep elements who is greater or eql to its all left elements in window
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        // push the first maximum from dq
        ans.push_back(arr[dq.front()]);
        
        // now we'll traverse rest of the eles
        for(int i = k; i<n; i++) {
            // first we'll remove the ele which is now outside of the window of k size (i - k) ele
            // this out sider element always must be on the front of dq or no where on dq
            if(arr[dq.front()] == arr[i-k]) dq.pop_front();
            
            // now we'll again do the same process which we have done the above for loop
            
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
        
    }
