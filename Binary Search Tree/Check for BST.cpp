// Given the root of a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.
// A BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:

// Input:
//    2
//  /    \
// 1      3
// Output: 1 
// Explanation: 
// The left subtree of root node contains node
// with key lesser than the root nodes key and 
// the right subtree of root node contains node 
// with key greater than the root nodes key.
// Hence, the tree is a BST.

class Solution
{
    // bool ans = 1;
    public:
    //Function to check whether a Binary Tree is BST or not.
    int BST_MIN (Node* root) {
        if(root == NULL) return INT16_MAX;
        while(root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
    int BST_MAX(Node* root) {
        if(root == NULL)  return INT16_MIN;
        while(root->right != NULL)  root = root->right;
        return root->data;
    }
    bool isBST(Node* root) 
    {
        // Your code here
        if(root == NULL) return 1;
        if(root->left != NULL && BST_MIN(root->left) >= root->data) return 0;   // left node's Min would be lesser than the current node
        if(root->left != NULL && BST_MAX(root->left) >= root->data) return 0;   // left node's max also would be lesser than current node
        if(root->right != NULL && BST_MAX(root->right) <= root->data) return 0;   // right subtree's min would be greater than current node
        if(root->right != NULL && BST_MIN(root->right) <= root->data) return 0;   // right subtree's max would be greater than current node
        if(!(isBST(root->left) && isBST(root->right))) return 0;
        return 1;
    }
};
