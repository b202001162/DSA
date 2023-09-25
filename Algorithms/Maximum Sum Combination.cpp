// Time Complexity : O(N*LOG(N))
// Space complexity : O(N)

// Problem Statement :

// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation: 
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
// Example 2:

// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation: 
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤  105
// 1 ≤ K ≤  N
// 1 ≤ A [ i ] , B [ i ] ≤ 104



// Solution
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue <pair<int, pair<int, int>>> pq;
        vector <int> ans;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i = 0; i<N; i++) {
            pq.push({A[i] + B[N-1], {i, N-1}});
        }
        int x, y;
        while(K-- && !pq.empty()) {
            auto it = pq.top();
            ans.push_back(it.first);
            pq.pop();
            x = it.second.first;
            y = it.second.second;
            if(y!=0) {
              // push it's other combination if it's get added to the priority queue
                pq.push({A[x] + B[y-1], {x, y-1}});
            }
        }
        
        return ans;
    }
};
