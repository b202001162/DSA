// 530. Minimum Absolute Difference in BST

// Description: Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Input: root = [4,2,6,1,3]
// Output: 1


// Aproach: Here the minimum difference between two node must be between left subtree's max or right subtree's min.
//        8
//      /    \
//      3     15
//     / \    /
//    1   7  10
//  Here the minimum difference is 8 - 7 = 1

class Solution {
public:

    int maxBST (TreeNode* root) {  // IN BST the max ele is the rightest one
        if(root == NULL) return INT_MAX;
        while(root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }

    int minBST(TreeNode* root) {  // IN BST the min ele is the leftest one
        if(root == NULL) return INT_MAX;
        while(root->left != NULL) {
            root= root->left;
        }
        return root->val;
    }

    int DFS (TreeNode* root, int ans) {
        if(root== NULL) return INT_MAX;
        if(root->left != NULL)
            ans = min(ans, abs( root->val - maxBST(root->left)) );
        if(root->right != NULL)
            ans = min(ans, abs( root->val - minBST(root->right)));
        ans = min(ans, DFS(root->left, ans));
        ans = min(ans, DFS(root->right, ans));
        return ans;
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        if(root == NULL) {
            return INT_MAX;
        }
        ans = min(DFS(root, ans), ans);
        return ans;
    }
};
