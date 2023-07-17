// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

// Example 1:

// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7
// Example 2:

// Input:
//            7
//         /     \
//        9       7
//      /  \     /   
//     8    8   6     
//    /  \
//   10   9 
// Output:
// 7 7 9 8 8 6 9 10 
 

// Your Task:
// You don't need to read input or print anything. 
// Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and 
// returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.



class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    
    vector <int> levelOrderTra(Node* root) {
        if(root == NULL) return {};
        
        vector <int> ans;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        // to get disire level reverse order
        bool flag = 0;
        // for getting reverse order in perticular level
        stack<int>st;
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(front == NULL) {
                // NULL says now the last level is over
                if(!q.empty()) q.push(NULL);
                
                if(flag == 1) {
                    // if boolean is true then get all elements from stack, which all are in reverse ordered in odd level (0th indexed)
                    while(!st.empty()) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    flag = 0;
                }
                else flag = 1;
                
            } else {
                
                if(flag == 1) {
                    st.push(front->data);
                } else {
                    // if boolean is flase then take it as non reverse and push directly in the ans array
                    ans.push_back(front->data);
                }
                
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
        }
        return ans;
    }
    
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	return levelOrderTra(root);
    	
    }
};
