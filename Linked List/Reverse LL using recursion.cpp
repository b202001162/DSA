#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


*****************************************************************/

LinkedListNode <int>* reverse(LinkedListNode<int> *head) {
    // base case
    if(head == NULL || head->next == NULL) return head;

    LinkedListNode<int>* nextHead = reverse(head->next);   // recursive call for reverse next portion of Linked List

    head->next->next = head;  // 3 -> (head->next) 4 ->(head->next->next) -> ...
    // 3 -> 4
    // |----|
    head->next = NULL; // now node head->next to null
    // (NULL <- 3 <- 4) 
    // we have reversed portion of LL
    return nextHead;
}


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    head = reverse(head);
    return head;
}
