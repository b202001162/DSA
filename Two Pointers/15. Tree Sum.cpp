class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <int> temp(3);
        vector <vector <int>> ans;
        for(int i = 0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // it secures the redundant triplets
            int j = i+1, k = n-1;
            while(k > j) {
                if(nums[i] + nums[j] + nums[k] < 0) j++;
                else if(nums[i] + nums[j] + nums[k] > 0) k--;
                else {
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    ans.push_back(temp);
                    while (nums[j + 1] == nums[j] && j+1 < k) { // we will increase the j index until it get points to not the same number so no redundany will be there
                        j += 1; 
                    }
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
