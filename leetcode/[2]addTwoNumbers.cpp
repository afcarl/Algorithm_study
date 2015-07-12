class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		long long first_num = 0, second_num = 0;
		long long cnt = 1;
		while (l1) {
			first_num += l1->val * cnt;
			cnt *= 10;
			l1 = l1->next;
		}
		cnt = 1;
		while (l2) {
			second_num += l2->val * cnt;
			cnt *= 10;
			l2 = l2->next;
		}
		long long res1 = first_num + second_num;
		ListNode* res_list = new ListNode(res1 % 10);
		res1 /= 10;
		ListNode* temp = res_list;
		while (res1) {
			ListNode* x = new ListNode(res1 % 10);
			temp->next = x;
			temp = temp->next;
			res1 /= 10;
		}
		return res_list;
	}
};