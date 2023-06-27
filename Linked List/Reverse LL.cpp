void reverse(Node* head, Node* curr, Node* prev) {
  // base case
  if(curr == NULL) {
    head = prev;
  }

  Node* node = curr->next; // Create node that points to next node of current node
  curr->next = prev;  // current node, which will be points its next to previous node, reverse a node
  prev = curr;  // Previous node is previous node of current node
}

Node* solution (Node* head) {
  if(head == NULL || head->next == NULL) return head;
  Node* curr = head;
  Node* prev = NULL;
  reverse(head, curr, prev);
  return head;
}
