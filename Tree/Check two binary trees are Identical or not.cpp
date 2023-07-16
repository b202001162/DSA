class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        // if both are NULLs then it is okey
        if(r1 == NULL && r2 == NULL) return 1;
          // if any one is NULL, then also there not identical
        else if(r1 == NULL) return 0;
        else if(r2 == NULL) return 0;

      // if there values are not same then it is fault
        if(r1->data != r2->data) return 0;
        
        // left check
        bool flag = isIdentical(r1->left, r2->left);
        flag &= isIdentical(r1->right, r2->right);
        
        return flag;
    }
};
