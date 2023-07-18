// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Example 1:

// Input:
//            1
//          /   \
//        2       3
//      /   \   /   \
//    4      5 6      7
//               \      \
//                8      9           
// Output: 
// 4 2 1 5 6 3 8 7 9 
// Explanation:

// Example 2:

// Input:
//        1
//     /    \
//    2       3
//  /    \      \
// 4      5      6
// Output: 4 2 1 5 3 6
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


vector<int> verticalOrder(Node *root)
{
    //Your code here
    // map <horizntal distance, pair<lvl, {vector of nodes value}>
    map <int, map<int, vector <int>>> nodes;
    queue<pair<Node*, pair<int,int> > > q;
    
    q.push({root, {0,0}});
    while(!q.empty()) {
        pair<Node*, pair<int,int> >  front = q.front();
        q.pop();
        
        Node* frontNd = front.first;
        // horizontal Distance
        int horDis = front.second.first;
        // level of the node
        int lvl = front.second.second;
        
        // insert data to map of maps
        nodes[horDis][lvl].push_back(frontNd->data);
        // push left sub tree
        if(frontNd->left != NULL) q.push({frontNd->left, {horDis - 1, lvl+1}});
        // right sub tree
        if(frontNd->right != NULL) q.push({frontNd->right, {horDis + 1, lvl+1}});
        
    }
    
    vector <int>ans;
    
    for(auto i : nodes) {
        // target map from nodes map
        for(auto j : i.second) {
            // target vectors form map of nodes map
            for(auto k : j.second) {
                // target vector values form vector of maps of nodes map
                ans.push_back(k);
            }
        }
    }
    return ans;
}
