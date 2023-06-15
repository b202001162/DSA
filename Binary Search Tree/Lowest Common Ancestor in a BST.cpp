// Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

// Example 1:

// Input:
//               5
//             /   \
//           4      6
//          /        \
//         3          7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7

// O(LogN)

class Solution{
    Node* ans = NULL;
    public:
    
        void solv(Node* root, int n, int m) {
            if(ans != NULL) return;
            if(root == NULL) return;
            if(root->data < n && root->data < m) {
                solv(root->right, n, m);
                return;
            }
            else if(root->data > n && root->data > m) { 
                solv(root->left, n, m);
            }
            else {
                ans = root;
                return;
            }
        }
        
        Node* LCA(Node *root, int n1, int n2)
        {
            // Node *lca = NULL;
            
            // while(root != NULL){
            //     if(root->data < n1 && root->data < n2){
            //         root = root->right;
            //     }
            //     else if(root->data > n1 && root->data >n2){
            //         root = root->left;
            //     }
            //     else{
            //         lca = root;
            //         return lca;
            //     }
            // }
            
            solv(root, min(n1, n2), max(n1, n2));
            return ans;
        }

};
