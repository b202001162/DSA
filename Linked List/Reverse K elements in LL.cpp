/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */


Node* reverse(Node* head, int k) {
    // 
    if(head == NULL) return head;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int ctn = 0;
    while(ctn < k && curr != NULL) {
        ctn++;
        curr = curr->next;
    }
    bool flag = 0;
    if(ctn == k) flag = 1; // when last eles count is K
    else return head; // when last elements count is less than K
    ctn = 0;
    curr = head;
    while(ctn < k && curr != NULL) { // run untill ctn is less than and Curr is not null
        ctn++;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    if(forward != NULL) {
        head->next = reverse(forward, k);    // point head->next to next recursive node's head;
    }

    return prev;
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    if( k == 1) {
        return head;
    }
    head = reverse(head, k);
    return head;
}
