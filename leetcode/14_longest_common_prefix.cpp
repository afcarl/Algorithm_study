/*
 * 14_longest_common_prefix.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/12/25/LeetCode-Report-11-15/
 */

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int cnt = 0;
    bool flag = true;
    while (flag && strs.size() != 0) {
      char symbol, cmp;
      for (int i=0; i<strs.size(); ++i) {
	string current_string = strs[i];
	if (cnt >= current_string.size()) {
	  flag = false;
	  break;
	}

	if (i == 0) {
	  symbol = current_string[cnt];
	} else {
	  cmp = current_string[cnt];
	}

	if (symbol != cmp) {
	  flag = false;
	  break;
	}
      }
      if (flag) cnt++;
    }
    if (strs.size() == 0) return "";
    else {
      if (cnt == 0) return "";
      else return string(strs[0].begin(), strs[0].begin() + cnt);
    }
  }
};
