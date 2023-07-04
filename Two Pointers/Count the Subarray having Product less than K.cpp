// Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

// Example 1:

// Input : 
// n = 4, k = 10
// a[] = {1, 2, 3, 4}
// Output : 
// 7
// Explanation:
// The contiguous subarrays are {1}, {2}, {3}, {4} 
// {1, 2}, {1, 2, 3} and {2, 3} whose count is 7.

class Solution{
  public:
    
    int totalSubArray (int n) {
        return (n * (n+1))/2;
    }
    
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i = 0, j = 0,ans = 0;
        long long currProd = 1;
        while(i < n && j < n) {
            // if the currProd is lessthan the k then we increase the diffrece between i and j.
            // OW we increase ith index and then continue
            if(currProd*a[j] >= k) {
                if(j == i) {
                    j++;
                    i++;
                    continue;
                }
                currProd /= a[i];
                // add difference each time when the product exceed K or equal to k
                ans += (j - i);
              // increase the i OR decrease the diffrence
                i++;
            }
            else {
                currProd *= a[j];
                j++;
            }
        }
        // at last calculate the total subarray which are formed by the diffrence
        ans += totalSubArray(j - i);
        return ans;
    }
};
