class Solution{
    public:
    
    int findPos(int *in, int s, int e, int target) {
      // find element of preOrdered's in in order
        for(int i = s; i<=e; i++) {
            if(target == in[i]) return i;
        }
    }
     
    Node* inAndpreToPost(int *in, int *pre, int n, int inOrdStart, int inOrdEnd, int &index) { 
      // here we include call index as referce because we don't we the left sub tree is going to over
      // when index is n or more OR when inStart is bigger than inEnd then return NULL;
        if(index >= n || inOrdStart > inOrdEnd) return NULL;
        
        Node* root = new Node(pre[index]);
        // find position in inordered 
        int pos = findPos(in, inOrdStart, inOrdEnd, pre[index++]);
        // left subtree call
        root->left = inAndpreToPost(in, pre, n, inOrdStart, pos-1, index);
        // right subtree call
        root->right = inAndpreToPost(in, pre, n, pos+1, inOrdEnd, index);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        if(n == 0) return NULL;
        int ind = 0;
        Node* root= inAndpreToPost(in, pre, n, 0, n-1, ind);
        
        return root;
        
    }
};
