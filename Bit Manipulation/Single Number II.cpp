class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<32; i++) {
            int sum = 0;
            for(auto n : nums) {
                sum += n>>i&1; // for getting ith bit of all numbers
            }
            sum =sum%3;  // for getting ith bit of the once number
            ans = ans|(sum<<i); // add the ith bit of target number to ans's ith bit
        }
        return ans;
    }
};
