class Solution {
  public:
    // Function to return the diameter of a Binary Tree
    pair <int, int> Diameter (Node* root) {
      // second argument for height and first is for getting the diameter
        // O(n) time complexity
        if(root == NULL) return {0,0};
        
        pair <int, int> left = Diameter(root->left);
        pair<int, int> right = Diameter(root->right);
        
        int value1 = left.first;
        int value2 = right.first;
        int value3 = left.second + right.second + 1;
        
        return {max(max(value1, value2), value3), max(left.second, right.second) + 1};
    }
    
    int diameter(Node* root) {
        // Your code here
        
        // base case
        if(root == NULL) return 0;
        
        return Diameter(root).first;
        
    }
};
