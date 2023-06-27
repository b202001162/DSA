/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node *removeLoop(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if(fast != NULL) fast = fast -> next;
        slow = slow->next;
        if(fast == slow) break;
    }

    if(fast == NULL)  return head;   // When fast is NULL means there is not present any loop or cycle

    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast -> next;
    }

    if(slow == NULL) return NULL;   // when there is no of nodes is zero

    while(slow->next != fast) slow = slow->next; // find the node which is previous of the begining of the loop node

    slow->next = NULL; // the previous node which is cause thr loop, we will asign it as NULL pointer

    return head;  // return the head which does not have any loop
}
