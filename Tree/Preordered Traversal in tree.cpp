//  Preordered Traversal: Node Left Right

void preOrderedTraversal (node* root) {
    // base case
    if(root == NULL) return;
    
    // call node means print it's data
    cout << root -> data << " ";
    
    // call left node
    preOrderedTraversal(root->left);
    
    // call right node
    preOrderedTraversal(root->right);
    
    return;
}
