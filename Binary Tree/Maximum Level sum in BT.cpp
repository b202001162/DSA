// Description: 
// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.

// Inordered Tranversal in BS
// Breadth First Search

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = -1;
        queue <TreeNode*> q;
        q.push(root);
        int maxLevelSum = INT_MIN;
        for(int level = 1; !q.empty(); ++level) { // Travels until the queue is not empty
            int levelSum = 0;
            for(int i = q.size(); i>0; i--) { // it is run for old queue that contains only the parents not node->left or node->right
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left!=NULL) q.push(node->left); // These childeren may execute in next level
                if(node->right!=NULL) q.push(node->right);
            }
            if(levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                ans = level;
            }
        }
        return ans;
    }
};
