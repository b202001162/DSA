
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to find the height of a binary tree.
    
    void height(Node* root, int &ans, int count) {
        // inordered traversal
        if(root == NULL) return;
        // count++;
        height(root->left, ans, count+1);
        // count--;
        
        if(root->left == NULL && root->right ==NULL)  {
            ans = max(count, ans);
            return;
        }
        
        height(root->right, ans, count+1);
    }
    
    int height(struct Node* node){
        // code here 
        int ans = 0;
        height(node, ans, 1);
        return ans;
    }
};
