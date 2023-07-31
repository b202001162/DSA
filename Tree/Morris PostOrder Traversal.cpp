/// this function is code semilar to inorder traversal, just all the left replace to the right pointers and viseversa.

vector <int> morrisPostOrder(Node* root) {
  vector <int> ans;
  if(root == NULL) return ans;

  Node *curr = root, *prev = NULL;

  while(curr!=NULL) {
    if(curr -> right == NULL) {
      ans.push_back(curr->val);
      curr = curr->left;
    } else {
      prev = curr->right;
      while(prev->left != NULL and prev->left != curr) {
        prev = prev->left;
      }
      if(prev->left == NULL) {
        prev->left = curr;
        curr = curr->right;
      } else {
        prev->left = NULL;
        ans.push_back(curr->val);
        curr = curr->left;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
  
}
