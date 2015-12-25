/*
 * 12_integer_to_roman.cpp
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
  string intToRoman(int num) {
    string res = "";
    string symbol_table[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value_table[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i=0; i<13; ++i) {
      while (num >= value_table[i]) {
	res += symbol_table[i];
	num -= value_table[i];
      }
    }
    return res;
  }
};
