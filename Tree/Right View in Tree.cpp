// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Example 1:

// Input:
//        1
//     /    \
//    3      2
// Output: 1 2
// Example 2:

// Input:
//      10
//     /   \
//   20     30
//  /   \
// 40  60 
// Output: 10 30 60
// Your Task:
// Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).



vector<int> rightView(Node *root)
{
   // Your Code here
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
               // if q is non empty then add it's last ele to the ans, because it's always be the rightest ele level wise
               ans.push_back(q.back()->data);
             // push NULL for indicator for the level has been changed
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
