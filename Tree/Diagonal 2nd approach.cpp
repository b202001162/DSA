vector<int> diagonal(Node *root) {
   vector<int> ans;
   queue<Node*> q; q.push(root);
   while (!q.empty()) {
       Node *node = q.front(); q.pop();
       while (node) {
         // traverse all the right nodes first and push it's left nodes to the queue;
           ans.push_back(node->data);
           q.push(node->left);
           node = node->right;
       }
   }
   return ans;
}
