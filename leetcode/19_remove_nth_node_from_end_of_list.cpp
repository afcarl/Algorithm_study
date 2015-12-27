/*
 * 19_remove_nth_node_from_end_of_list.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/12/26/LeetCode-Report-16-20/
 */

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* ptr = head;

    while (ptr) {
      size += 1;
      ptr = ptr->next;
    }
    if (size == 0 || size == 1) return NULL;

    ptr = head->next;
    ListNode* pre = head;
    for (int i=1;i<size-n;++i) {
      ptr = ptr->next;
      pre = pre->next;
    }

    if (n == size) {
      head = head->next;
    } else {
      pre->next = ptr->next;
    }
    return head;
  }
};
