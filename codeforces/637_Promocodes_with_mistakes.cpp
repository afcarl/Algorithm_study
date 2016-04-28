/*
 * 637_Promocodes_with_mistakes.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2016 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  std::cin >> n;
  vector<string> promo_codes;
  for (int i = 0; i < n; ++i) {
    string s;
    std::cin >> s;
    promo_codes.push_back(s);
  }
  
  int code_length = promo_codes[0].size();
  int diff_code = code_length;
  if (promo_codes.size() == 1) {
    std::cout << diff_code << std::endl;
    return 0;
  }
  
  for (int i = 0; i < promo_codes.size(); ++i) {
    for (int j = i+1; j < promo_codes.size(); ++j) {
      int diff_cnt = 0;
      for (int k = 0; k < code_length; ++k) {
	diff_cnt += (promo_codes[i][k] != promo_codes[j][k]);
      }
      diff_code = std::min(diff_cnt, diff_code);
    }
  }
  std::cout << (diff_code - 1) / 2 << std::endl;
  return 0;
}
