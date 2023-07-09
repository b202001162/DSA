time: O(n^3)
space: O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k, l;
        long long sum;
        vector <int> temp(4);
        vector <vector <int>> ans;
        for(int i = 0; i<n; i++) {
            if(i>0 && nums[i-1] == nums[i]) continue; // if prev ele is used for creating the 4sum then we have to continue (for ensure no redundancy in the ans)
            for(int j = i+1; j <n; j++) {
                if(j-1>i && nums[j-1] == nums[j]) continue; // if prev ele is used for creating the 4sum then we have to continue (for ensure no redundancy in the ans)
                k = j+1, l = n-1;
                while(l > k) {
                    if(l > k && k-1>j && nums[k-1] == nums[k]) { // if prev ele is used for creating the 4sum then we have to continue (for ensure no redundancy in the ans)
                        k++;
                        continue;
                    }
                    sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else {
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        temp[3] = nums[l];
                        ans.push_back(temp);
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
