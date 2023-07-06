/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward  = NULL;
        while(curr != NULL) {
            forward = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // to get mid index or pointer of the list
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reversableNode = slow->next;
        slow->next = NULL;
        reversableNode = reverseList(reversableNode);
        slow = head;
        while(reversableNode != NULL && slow != NULL) {
            // reoreder the list
            ListNode* temp = slow->next;
            slow->next = reversableNode;
            slow = slow->next;
            reversableNode = reversableNode->next;
            slow->next = temp;
            slow = temp;
        }
        return;
    }
};
