
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> table;
    int left = 0, max_len = 0;
    for (int i=0;i<s.size();++i) {
      if (s[i] == '(') {
	table.push(i);
      } else {
	if (table.empty()) {
	  left = i+1;
	} else {
	  table.pop();
	  int left_parenthese = table.empty() ? left : table.top() + 1;
	  int dist = i - left_parenthese + 1;
	  max_len = max_len > dist ? max_len : dist;
	}
      }
    }
    return max_len;
  }
};
