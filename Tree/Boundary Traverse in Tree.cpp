class Solution {
public:
    
    void traverseLeft(Node* root, vector <int>&ans) {
        // base cae
        if(root ==NULL || (root->left == NULL && root->right == NULL)) return;
        
        // append in the ans
        ans.push_back(root->data);
        
        // if it's a leaf or it's left is not present then don't add it to ans;
        if(root->left != NULL) traverseLeft(root->left, ans);
        else traverseLeft(root->right, ans);
        
        return;
    }
    
    void traverseRight(Node* root, vector <int>&ans) {
        if(root ==NULL || (root->left == NULL && root->right == NULL)) return;
        
        // call right subtree
        
        if(root->right != NULL) traverseRight(root->right, ans);
        else traverseRight(root->left, ans);
        
        // we first call right substree then append to the ans vector, because we want to add then in reverse order
        ans.push_back(root->data);
    }
    
    void findLeafNode(Node* root, vector <int>&ans) {
        if(root == NULL) return;
        
        if(root->left == NULL and root->right ==NULL) {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left != NULL) findLeafNode(root->left, ans);
        
        if(root->right != NULL) findLeafNode(root->right, ans);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root == NULL)  return {};
        vector <int> ans;
        
        ans.push_back(root->data);
        
        traverseLeft(root->left, ans);
        
        findLeafNode(root->left, ans);
        findLeafNode(root->right, ans);
        
        traverseRight(root->right, ans);
        
        return ans;
        
        
    }
};
