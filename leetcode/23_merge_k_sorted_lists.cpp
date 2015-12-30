
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int l = 0, r = lists.size() - 1;
    if (lists.size() == 0) return NULL;
    return recur_merge(lists, l, r);
  }

private:

  ListNode* recur_merge(vector<ListNode*>& lists, int l, int r) {
    if (l < r) {
      int m = (l+r)/2;
      ListNode* left = recur_merge(lists, l, m);
      ListNode* right = recur_merge(lists, m+1, r);
      return mergeTwoLists(left, right);
    } else {
      return lists[l];
    }
  }


  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while (l1 && l2) {
      int cur_val;
      if(l1->val > l2->val) {
	cur_val = l2->val;
	l2 = l2->next;
      } else {
	cur_val = l1->val;
	l1 = l1->next;
      }
      cur->next = new ListNode(cur_val);
      cur = cur->next;
    }

    if (l1) {
      cur->next = l1;
    } else {
      cur->next = l2;
    }
    return head->next;
  }

};
