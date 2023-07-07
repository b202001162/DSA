// Problem Description

// Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

// B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



// Problem Constraints
// 1 <= length of the string <= 100000



// Input Format
// The only argument given is string A.



// Output Format
// Return a string B after processing the stream of lowercase alphabets A.



// Example Input
// Input 1:

//  A = "abadbc"
// Input 2:

//  A = "abcabc"


// Example Output
// Output 1:

//  "aabbdd"
// Output 2:

//  "aaabc#"


string Solution::solve(string s) {
    int n = s.size();
    int index = 0;
    string ans = "";
    unordered_map <int, int> mp;
    for(int i = 0; i<n; i++) {
        mp[s[i]]++;
        while(mp[s[index]] > 1 && index <= i) {
            // until we will find the correct index
            index++;
        }
        if(index==i+1) {
            // if index exceed the currentIndex i then we push # to the ans string
            ans+='#';
        }
        else ans+=s[index];
    }
    return ans;
}
