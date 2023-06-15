// Given an array A of N elements. 
// Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// TC = O(N)

class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        int ans = -1;
        unordered_map <int, int> mp;
        for(int i= 0; i<n; i++) {
            mp[a[i]]++;
        }
        for(auto i: mp) {
            if(i.second > n/2) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};
