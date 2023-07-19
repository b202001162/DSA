Node* lca(Node* root ,int &n1 ,int &n2 ) {
   //Your code here 
   
   if(root==NULL) return NULL;
   
   if(root->data == n1 || root->data == n2) {
       return root;
   }
   
   Node* leftNode = lca(root->left, n1, n2);
   Node* rightNode = lca(root->right, n1, n2);
   
   if(leftNode != NULL && rightNode != NULL) return root; // always the ans OR least common ancestor
   else if(leftNode != NULL && rightNode == NULL) return leftNode; // if leftNode is n1 or n2 and also have n2 OR n1 beneath itself
   else if(leftNode == NULL && rightNode != NULL) return rightNode;
   else NULL; // if not present
    
}
