// Left most node is always minimum in BST


int minBST(Node* root) {
    if(root == NULL) return -1;
    while(root->left) {
        root = root->left;
    }
    return root->data;
}

int minValue(Node* root) {
    // Code here
    int ans = minBST(root);
    return ans;
}
