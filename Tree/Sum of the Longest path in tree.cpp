// TC O(n) && SC O(n)

// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

// Example 1:

// Input: 
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3    
//       /
//      6
// Output: 13
// Explanation:
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3 
//       /
//      6

// The highlighted nodes (4, 2, 1, 6) above are 
// part of the longest root to leaf path having
// sum = (4 + 2 + 1 + 6) = 13
// Example 2:

// Input: 
//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7
// Output: 11
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

void backTrack(Node* root, pair<int, int>& ans, pair<int, int> &sum) {
        // base case
        if(root==NULL) return;
        
        // add current node data to sum first
        sum.first+=root->data;
        // node count increament
        sum.second++;
        
        if(root->left == NULL && root->right == NULL)  {
            if(sum.second > ans.second) {
                // if current path node counts is greater than any other path then take first (sum of all nodes in current path) as ans and update count of the ans pair or longest l=path
                ans.second = sum.second;
                ans.first = sum.first;
            } else if(sum.second == ans.second) {
                // if current path node count is equalt to any other longest path then the ans is the maximum of the both of them
                ans.second = sum.second;
                ans.first = max(ans.first, sum.first);
            }
        }
        
        // left call
        if(root->left) backTrack(root->left, ans, sum);
        
        // right call
        if(root->right) backTrack(root->right, ans, sum);
        
        // backtrack
        sum.first -= root->data;
        sum.second--;
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        pair<int, int> ans = {0, 0}, sum = {0, 0};
        
        backTrack(root, ans, sum);
        
        return ans.first;
    }
