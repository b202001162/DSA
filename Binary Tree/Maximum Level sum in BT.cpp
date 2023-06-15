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
