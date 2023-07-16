class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    pair <bool, int> solv(Node* root) {
        // first argument for true or false and second for height of tree
        // base case
        if(root==NULL) return {true,0};
        
        // ask to the left child
        pair<bool, int> left = solv(root->left);
        
        // ask to right child 
        pair<bool, int> right = solv(root->right);
        
        bool bValue = left.first;
        bValue &= right.first;
        bValue &= (abs(left.second - right.second) <= 1);
        
        return {bValue, max(left.second, right.second) + 1};
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        // return first bool variable of a pair
        return solv(root).first;
    }
};
