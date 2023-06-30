class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* node) {
        // reverse a LL
        Node* curr = node;
        Node* prev = NULL;
        Node* forw = NULL;
        
        while(curr != NULL) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        Node* ans = new Node(-1);
        Node* node = ans;
        Node* node1 = first;
        Node* node2 = second;
        
        int carry = 0;
        
        while(node1 != NULL && node2 != NULL) {
            Node* newNode = new Node(node1->data + node2->data + carry);
            carry = newNode->data/10;
            newNode->data = newNode->data%10;
            node->next = newNode;
            node = node->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        while(node1 != NULL) {
            // remaining first linked list
            Node* newNode = new Node(node1->data + carry);
            carry = newNode->data/10;
            newNode->data = newNode->data%10;
            node->next = newNode;
            node = node->next;
            node1 = node1->next;
        }
        while(node2 != NULL) {
            // reamianing second linked list
            Node* newNode = new Node(node2->data + carry);
            carry = newNode->data/10;
            newNode->data = newNode->data%10;
            node->next = newNode;
            node = node->next;
            node2 = node2->next;
        }
        while(carry != 0) {
            //  reamining carry 
            Node* newNode = new Node(carry);
            carry = newNode->data/10;
            newNode->data = newNode->data%10;
            node->next = newNode;
            node = node->next;
            // node1 = node1->next;
        }
      // ans's first node is garbege node or not in used node
        ans->next = reverse(ans->next);
      // reverse the ans linked list
        return ans->next;
    }
};
