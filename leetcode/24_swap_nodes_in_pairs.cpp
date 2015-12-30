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
  ListNode* swapPairs(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    if (cur == NULL) return NULL;
    ListNode* nex = head->next;
    if (nex == NULL) return head;
    else {
      head = nex;
    }

    while (cur && cur->next) {
      ListNode* tmp = nex->next;
      if (pre != NULL) pre->next = cur->next;
      nex->next = cur;
      cur->next = tmp;
      pre = cur;
      cur = cur->next;
      if (cur) nex = cur->next;
    }
    return head;
  }
};
