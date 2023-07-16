// Post Ordered traversal : Left Right Node

void postOrderedTraversal (node* root) {
    // base case
    if(root == NULL) return;
    
    // call left node
    postOrderedTraversal(root->left);
    
    // call right node
    postOrderedTraversal(root->right);
    
    // print node-> data
    cout << root->data << " ";
    
    return;
}
