class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 0) return;
        vector <int> v(3, 0);
        for(int i = 0; i<n; i++) {
            v[nums[i]]++;
        }
        int index = 0;
        for(int i = 0; i<n; i++) {
            if(v[index]>0) {
                nums[i] = index;
                v[index]--;
            }
            else {
                index++;
                i--;
            }
        }
        return;
    }
};
