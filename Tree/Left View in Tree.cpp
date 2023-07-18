// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Example 1:

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3

// Example 2:

// Input:

// Output: 10 20 40
// Your Task:
// You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).






vector<int> leftView(Node *root)
{
   // Your code here
   
   if(root==NULL)  return {};
   
   vector <int> ans;
   ans.push_back(root->data);
   queue <Node*> q;
   q.push(root);
   q.push(NULL);
   
   while(!q.empty()) {
       Node* frontNode = q.front();
       q.pop();
       
       if(frontNode == NULL) {
           if(!q.empty()) {
             // no empty then take it's front ele in ans, this ele is leftest ele level wise
               ans.push_back(q.front()->data);
               q.push(NULL);
           }
       }
       else {
           
           if(frontNode->left) q.push(frontNode->left);
           if(frontNode->right) q.push(frontNode->right);
       }
   }
   
   return ans;
}
