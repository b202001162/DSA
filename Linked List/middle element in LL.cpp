/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL) {
        fast = fast->next; // Fast runs two times 
        if (fast != NULL) {
          fast = fast->next;
          slow = slow->next; // slow run one time
        }
    }
    // int ans = slow->data;
    return slow; // at the end slow will be middle index or element of linked list
}

