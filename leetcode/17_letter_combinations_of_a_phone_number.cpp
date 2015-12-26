/*
 * 17_letter_combinations_of_a_phone_number.cpp
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
  Solution() {
    string symbol_table[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (int i=0;i<10;++i) {
      map_table.insert(make_pair(i, symbol_table[i]));
    }
  }

  vector<string> letterCombinations(string digits) {
    return dfs(digits);
  }

private:
  map<int, string> map_table;

  vector<string> dfs(string digits) {
    vector<string> res;

    if (digits.size() == 0) {
      return res;
    } else {
      char digit = digits[0];
      string rest_digit = string(digits.begin() + 1, digits.end());
      vector<string> tmp = dfs(rest_digit);
      string digit_symbol = map_table[digit - '0'];
      for (int i=0;i<digit_symbol.size();i++) {
	if (tmp.size() == 0) {
	  res.push_back(string(1, digit_symbol[i]));
	} else {
	  for (int j=0;j<tmp.size();++j) {
	    res.push_back(digit_symbol[i] + tmp[j]);
	  }
	}
      }
    }

    return res;
  }
};
