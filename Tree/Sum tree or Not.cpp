// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


// Example 1:

// Input:
//     3
//   /   \    
//  1     2

// Output: 1
// Explanation:
// The sum of left subtree and right subtree is
// 1 + 2 = 3, which is the value of the root node.
// Therefore,the given binary tree is a sum tree.
// Example 2:

// Input:

//           10
//         /    \
//       20      30
//     /   \ 
//    10    10

// Output: 0
// Explanation:
// The given tree is not a sum tree.
// For the root node, sum of elements
// in left subtree is 40 and sum of elements
// in right subtree is 30. Root element = 10
// which is not equal to 30+40.


class Solution
{
    public:
    
    pair <bool, int> isOkey(Node* root) {
        
        // base case
        if(root == NULL) return {true,0};
        
        pair<bool, int> left = isOkey(root->left);
        
        pair<bool, int> right = isOkey(root->right);
        
        bool flag = left.first;
        flag &= right.first;
      // always true for the leaf nodes
        if(!(root->left == NULL && root->right == NULL))
            flag &= (left.second + right.second == root->data);
        
        return {flag, root->data + left.second + right.second};
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         
         return isOkey(root).first;
         
    }
};
