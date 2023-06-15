// TC = O(N*log(N))
// SC = O(N)

// Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  
// The output elements should be printed in decreasing order.
  
//  Input:
// N = 5, K = 2
// Arr[] = {12, 5, 787, 1, 23}
// Output: 787 23
// Explanation: 1st largest element in the
// array is 787 and second largest is 23.

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue <int, vector <int>, greater <int>> p;
	    for(int i= 0; i<n; i++) {
	        p.push(arr[i]);
	        if(p.size() > k) {
	            p.pop();
	        }
	    }
	    vector <int> ans (k);
	    for(int i = k-1; i >=0; i--) {
	        ans[i] = p.top();
	        p.pop();
	    }
	    return ans;
	}

};
