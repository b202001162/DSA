
// refere notebook for more explaination or understanding





class Solution {
private:
    void permutation(int index, vector <int> nums, vector <vector <int>>& ans, int n) {
        // base case
        if(index >= n) {
            // at the end the nums is one of the permutations of the given string
            ans.push_back(nums);
            return;
        }

        for(int i = index; i<n; i++) {
            // changing position of all nodes for permutation
            swap(nums[i], nums[index]);
            permutation(index+1, nums, ans, n);
            // back tracking (back to previous state) OR (regain previous state)
            swap(nums[i], nums[index]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> ans;
        vector <int> output;
        permutation(0, nums, ans, n);
        return ans;
    }
};
