/*
 * 20_valid_parentheses.cpp
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

class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2 == 1) {
      return false;
    }
    stack<char> table;
    for (int i=0;i<s.size();++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
	table.push(s[i]);
      } else {
	if (table.empty()) {
	  return false;
	} else {
	  char t = table.top();
	  table.pop();
	  if (s[i] - t <= 2 && t - s[i] >= -2 && s[i] != t) {
	    continue;
	  } else {
	    return false;
	  }
	}
      }
    }

    return table.empty();
  }
};
