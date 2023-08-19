/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // here node->val always distinct, and it upper bound is 100, so I created 101 sized vector mp
    void clone(Node* node, vector <Node*> &mp) {
        if(node == NULL) return;

        Node* root = new Node(node->val);
        mp[node->val] = root;

        for(auto i: node->neighbors) {
            if(mp[i->val] != NULL) {
                root->neighbors.push_back(mp[i->val]);
            } else {
                clone(i, mp);
                root->neighbors.push_back(mp[i->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector <Node*> mp(101, NULL);
        clone(node, mp);
        return mp[node->val];

    }
};
