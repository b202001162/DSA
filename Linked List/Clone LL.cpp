class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        unordered_map <Node*, Node*>mp;
        Node* node = head;
        Node* ans = new Node(-1);
        Node* newNode = ans;
        while(node != NULL) {
            Node* temp  = new Node(node->data);
            // set bidiractional for random pointer access
            mp[temp] = node;
            mp[node] = temp;
            newNode->next = temp;
            newNode = newNode->next;
            node = node->next;
        }
        
        node = head;
        newNode = ans->next;
        
        while(newNode != NULL) {
          // set random pointer algo
            newNode->arb = mp[mp[newNode]->arb];
            newNode = newNode->next;
        }
        
        return ans->next;
        
    }

};
