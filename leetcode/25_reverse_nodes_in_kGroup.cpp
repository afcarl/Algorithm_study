/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 1;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = head;
    ListNode* pre = dummy;
    while (cur) {
      if (!(cnt % k)) {
	pre = reverseK(pre, cur->next);
	cur = pre->next;
      } else {
	cur = cur->next;
      }
      cnt++;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }

private:
  ListNode* reverseK(ListNode* head, ListNode* tail) {
    assert(head);
    assert(head->next);
    ListNode* pre = head->next;
    ListNode* cur = pre->next;
    while (cur != tail) {
      pre->next = cur->next;
      cur->next = head->next;
      head->next = cur;
      cur = pre->next;
    }
    return pre;
  }
};
