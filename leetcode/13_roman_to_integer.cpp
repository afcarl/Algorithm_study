/*
 * 13_roman_to_integer.cpp
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
  int romanToInt(string s) {
    string symbol_table[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int value_table[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    int res = 0;
    for (int i = 0; i<s.size(); ++i) {

      bool flag = false;

      for (int j = 0; i + 1 < s.size() && j < 13; ++j) {
	string tmp = ""; tmp = tmp + s[i] + s[i + 1];
	if (tmp == symbol_table[j]) {
	  i++;
	  res += value_table[j];
	  flag = true;
	  break;
	}
      }

      if (flag) continue;

      for (int j = 0; j < 13; ++j) {
	string tmp(1, s[i]);
	if (tmp == symbol_table[j]) {
	  res += value_table[j];
	  break;
	}
      }
    }
    return res;
  }
};
