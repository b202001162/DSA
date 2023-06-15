// Given a Binary Tree, write a function to populate next pointer for all nodes. 
// The next pointer for every node should be set to point to inorder successor.

// Example 1:

// Input:
//            10
//        /  \
//       8    12
//      /
//     3
  

// Output: 3->8 8->10 10->12 12->-1
// Explanation: The inorder of the above tree is :
// 3 8 10 12. So the next pointer of node 3 is 
// pointing to 8 , next pointer of 8 is pointing
// to 10 and so on.And next pointer of 12 is
// pointing to -1 as there is no inorder successor 
// of 12.

// TC = O(N);
// SC = O(2N) = O(N);

class Solution
{
    unordered_map <int, Node*> mp;
    vector <int> v;
public:
    
    void inord(Node* root) {
        if(root==NULL) return;
        inord(root->left);
        mp[root->data] = root;
        v.push_back(root->data);    // save inordered wise node's value
        inord(root->right);
    }
    
    void populateNext(Node *root)
    {
        //code here
        Node* lastNode = new Node(-1);
        Node* node = root;
        inord(node);
        for(int i = 0; i<v.size()-1; i++) {
            mp[v[i]]->next = mp[v[i+1]];   // Set next to inordered successor
        }
        return;
    }
};
