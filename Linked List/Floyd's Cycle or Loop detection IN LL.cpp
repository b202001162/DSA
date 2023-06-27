bool solution(Node* head) {
  if(head == NULL) return 1;
  Node* fast = head->next;  // take two steps at once
  Node* slow = head->next;  // take a step at once

  while(fast != NULL) {
    if(fast == slow) {  // when both nodes become equal then we can say that, the cycle is present
      return 1;
    }
    fast = fast->next;
    if(fast != NULL)
      fast = fast->next;
    slow = slow->next;
  }
  return 0;
}
