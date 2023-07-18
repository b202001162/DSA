// Approach : traversal all right nodes of the front node, if any node has left child then push it to queue, for further diagonal traversal
// Another Approach: DO right view traversal, but here take same HD for all it's right children and increamental HD for it's left child

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

// Example 1:

// Input :
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4
// Explanation:
// unnamed
// Diagonal Traversal of binary tree : 
//  8 10 14 3 6 7 13 1 4
// Your Task:
// You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).


vector<int> diagonal(Node *root)
{
   // your code here
   if(root == NULL) return {};
   vector<int>ans;
   
   queue <Node*>q;
   q.push(root);
   
   while(!q.empty()) {
       // all front nodes may be left nodes which are pushed by right traversal, explain below
       Node* front = q.front();
       q.pop();
       // traverse all right of front node and push it's right node if available
       while(front != NULL) {
           if(front->left) q.push(front->left);
           ans.push_back(front->data);
           front=front->right;
       }
   }
   
   return ans;
}
