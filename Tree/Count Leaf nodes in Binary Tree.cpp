// inordered traversal

void countNode(node *root, int &ans) {
  // base cases
    if(root == NULL) return;

    // base case
    if(root->left == NULL && root->right == NULL) {
        ans++;
        return;
    }

    // left call
    countNode(root->left, ans);

    // right call
    countNode(root->right, ans);
}
