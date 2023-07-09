class Solution {
public:

    void generate(vector<string>& vec, string output, int open, int close, int n){
       if(open==n and close==n){
            vec.push_back(output);
            return;
        }
        if(open<n)
            generate(vec, output+"(" , open+1, close, n); // it func call like backtracking
        if(close<open)
            generate(vec, output+")", open, close+1, n); // its func call is like backtracking

      return;
    }

    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        generate(ans, "", 0, 0, n);
        return ans;
    }
};
