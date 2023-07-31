vector <int> morrisInOrder(Node* root) {
  vector <int> ans;
  if(root == NULL) return ans;

  Node *curr = root, *prev = NULL;
  // traverse until curr becomes null

  while(curr != NULL) {
    if(curr -> left == NULL) {
      // left most ele of curr's below subtree
      ans.push_back(curr->val);
      curr = curr->right;
    } else {
      prev = curr->left;
      // run until prev->right become NULL (so we encounter right most node first time) and prev->right becomes curr (if we encounter it before, for not trap in loop)
      while(prev->right!=NULL && prev->right!=curr) {
        prev = prev->right;
      }
      if(prev->right == NULL) {
        // for a link with the main parent (for going back)
        // this right most node is encounter first time
        prev->right = curr;
        curr = curr->left;
      } else {
        // if this node is alredy visited, so make it NULL, we don't want this parent child lin further, so make it like original tree
        prev->right = NULL;
        // right most ele
        ans.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  
  return ans;
}
