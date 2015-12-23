/*
 * 6_zigzag_conversion.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/12/23/LeetCode-Report-6-10/
 */

class Solution {
public:
  string convert(string s, int numRows) {
    int zigzag_size = 2*numRows - 2;
    string res = "";
    if (zigzag_size == 0) return s;
    for (int i=0;i<numRows && i < s.size();++i) {
      for (int j=0; j*zigzag_size+i < s.size(); j++) {
	res += s[j*zigzag_size + i];
	if (i != 0 && i != numRows-1
	    && (j+1) * zigzag_size - i < s.size()) {
	  res += s[j*zigzag_size + i + zigzag_size - i * 2];
	}
      }
    }
    return res;
  }
};

