/*
 * 5_longest_palindromic_substring.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/11/29/Leetcode-Report-1-5/
 */

class Solution {
public:
  string longestPalindrome(string s) {
    int C = 0, R = 0;
    string s_new = preprocess(s);
    vector<int> len;
    len.push_back(0);
    
    for (int i=1; i<s_new.size(); ++i) {
      int i_mirror = C-(i-C);
      if (R > i) {
	len.push_back(min(R-i, len[i_mirror]));
      } else {
	len.push_back(0);
      }
      
      while (s_new[i+1+len[i]] == s_new[i-1-len[i]]) {
	len[i]++;
      }
    }
    int max_len = 0, max_ind = 0;
    for (int i=0;i<len.size();++i) {
      if (max_len < len[i]) {
	max_len = len[i]; max_ind = i;
      }
    }
    
    return s.substr((max_ind - 1 - max_len)/2 ,max_len);
  }
  
  string preprocess(string s) {
    string res = "^";
    for (int i=0; i<s.size(); ++i) {
      res = res + "#" + s[i];
    }
    res += "#";
    return res;
  }
};
