class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long ans = INT_MAX;
        int j, k, sum;
        for(int i = 0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // it secures the redundant triplets
            j = i+1, k = n-1;
            while(k > j) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum < target) {
                    if(abs(target - sum) < abs(target - ans)) {
                        ans = sum;
                    }
                    j++;
                }
                else if(sum > target) {
                    if(abs(target - sum) < abs(target - ans)) {
                        ans = sum;
                    }
                    k--;
                }
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};
