InOrdered Traversal : Left Node Right


void inOrderedTraversal(node* root) {
    // int n = adj.size();
    if(root == NULL) return;
    
    // call left node
    inOrderedTraversal(root->left);
    
    // print node val
    cout << root->data <<  " ";
    
    // call right node
    inOrderedTraversal(root->right);
    
    return;
}
