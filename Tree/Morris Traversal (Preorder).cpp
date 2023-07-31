vector <int> morrisPreOrder(Node* root) {
  vector <int> ans;
  if(root==NULL) return ans;
  Node* curr = root, *prev = NULL;
  while(curr!=NULL) {
    if(curr->left ==NULL) {
      ans.push_back(curr->val);
      curr=curr->right;
    } else {
      prev = curr->left;
      while(prev->right!=NULL && perv->right!=curr) {
        prev = perv->right;
      }
      if(prev->right ==NULL) {
        ans.push_back(curr->val);
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = NULL;
        curr = curr->right;
      }
  }
  return ans;
}
