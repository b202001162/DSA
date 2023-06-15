// Inordered traversal of BST
// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

// Example 1:

// Input:
//         10
//       /   \
//      2    11
//    /  \ 
//   1    5
//       /  \
//      3    6
//       \
//        4
// key = 8
// Output: 
// 6 10
// Explanation: 
// In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.

class Solution
{
    // Global parameters
    int mini, maxi;
    Node* p = NULL;
    Node* s = NULL;
    public:
    void solv(Node* root, int k) {
        if(root == NULL) {
            return;
        }
        if(root->key < k && root->key > maxi) {
            p = root; // set predecessor node
            maxi = root->key;
        }
        if(root->key > k && root->key < mini) {
            mini = root->key;
            s = root; // set as successor node
        }
        solv(root->left, k);
        solv(root->right, k);
        return;
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        mini = INT_MAX, maxi = INT_MIN;
        if(root == NULL) {
            pre = NULL;
            suc = NULL;
            return;
        }
        solv(root, key);
        pre = p; 
        suc = s;
        return;
    }
};
