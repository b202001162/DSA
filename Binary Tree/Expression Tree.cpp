class Solution{
  public:
    /*You are required to complete below method */
    
    int solv(node* root) {
        if(root->left == NULL && root->right == NULL) {
            return stoi(root->data);
        }
        
        int temp1 = solv(root->left);
        
        char ch = root->data[0];
        
        int temp2 = solv(root->right);
        
        switch(ch) {
            case '+':
            return temp1 + temp2;
            break;
            
            case '*':
            return temp1 * temp2;
            break;
            
            case '/':
            return temp1 / temp2;
            break;
            
            case '-':
            return temp1 - temp2;
        }
        
    }
    
    int evalTree(node* root) {
        // Your code here
        int ans = 0;
        ans = solv(root);
        return ans;
    }
};
