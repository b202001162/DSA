class Node {
    public:
        int data;
        Node* left, *right;
        Node (int n) {
            data = n;
            left = NULL;
            right = NULL;
        }
};

struct cmp {
  bool operator () (Node* l, Node* r) {
      return l->data > r->data;
  }
};

class Solution
{
	public:
	
	    void findFreq (Node* root, vector <string> &ans, string &output) {
	        if(root->left == NULL && root->right == NULL) {
	            ans.push_back(output);
	            return;
	        }
	        // left recursive call
	        output += '0';
	        findFreq(root->left, ans, output);
	        output.pop_back();
	        
	        output += '1';
	        findFreq(root->right, ans, output);
	        output.pop_back();
	        
	        return;
	    }
	
		vector<string> huffmanCodes(string s,vector<int> arr,int n)
		{
		    // Code here
		    priority_queue <Node*, vector <Node*>, cmp> pq;
		    vector <string> ans;
		    for(int i = 0; i<n; i++) {
		        Node* temp = new Node(arr[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1) {
		        Node* frontFirst = pq.top();
		        pq.pop();
		        Node* frontSecond = pq.top();
		        pq.pop();
		        // create a new node
		        Node* node = new Node(frontFirst->data + frontSecond->data);
		        node->left = frontFirst, node->right = frontSecond;
		        
		        // push this node to the pq
		        pq.push(node);
		    }
		    string output = "";
		    Node* root = pq.top();
		    findFreq(root, ans, output);
		    return ans;
		}
};
