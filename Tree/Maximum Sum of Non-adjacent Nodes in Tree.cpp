// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

// Example 1:

// Input:
//      11
//     /  \
//    1    2
// Output: 11
// Explanation: The maximum sum is sum of
// node 11.
// Example 2:

// Input:
//         1
//       /   \
//      2     3
//     /     /  \
//    4     5    6
// Output: 16
// Explanation: The maximum sum is sum of
// nodes 1 4 5 6 , i.e 16. These nodes are
// non adjacent.
// Your Task:
// You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

// Expected Time Complexity: O(Number of nodes in the tree).
// Expected Auxiliary Space: O(Height of the Tree).



pair<int, int> solv(Node* root) {
        
    if(root == NULL) return {0,0};

    // left child
    pair <int, int> leftPair = solv(root->left);
    // right child
    pair<int, int> rightPair = solv(root->right);
    pair<int, int> p;
    // include the curr node
    p.first = leftPair.second + rightPair.second + root->data; // add it's children's excludeed parts for includeing the curretn node
    // exclude the current node
    // for excluding the current node, I can add included or Excluded sum of left Child and as well right child's
    p.second = max(leftPair.first,leftPair.second) + max(rightPair.first, rightPair.second); // add its children's included parts for excluding the current node
    
    return p;
}


int getMaxSum(Node *root) 
{
    // Add your code here
    // here we used approach of include and Exclude of nodes
    
    pair <int, int> ans = solv(root);
    
    return max(ans.first , ans.second);
    
}
