class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int createSumTree(Node* root) {
      
        if(root == 0) return 0;
        int temp;
        
        if(root->left == NULL && root->right == NULL) {
          // make leaf nodes zero
            temp = root->data;
            root->data = 0;
            return temp;
        }
        
        int left = createSumTree(root->left), right = createSumTree(root->right);

      // temp is reaturnable value to parent node
        temp = left + right + root->data;

      // make curr node value to it's sub tree's sum
        root->data = left + right;
        
        return temp;
        
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        
        if(node == NULL) return;
        
        createSumTree(node);
        
        return;
        
        
    }
};
