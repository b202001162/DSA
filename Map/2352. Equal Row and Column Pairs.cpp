// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]



class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector <vector <int>> g = grid;
        int n = g.size();
        vector <int> temp(n,0);
        unordered_map <vector <int>, int> mp;  // for lesser time complexity (than map<>)
        for(int i =0; i<n; i++) { // Add one by one all column in temp and then map them to @mp
            for(int j = 0; j<n; j++) {
                temp[j] =g[j][i];
            }
            mp[temp] += 1;
        }
        int ans = 0;
        for(auto i : g) { // Row wise thraversal
            if(mp.count(i) == 1) { // the row is present in @mp then ans ++
                ans+= mp[i];
            }
        }
        return ans;
    }
};
