/*
 * 7_reverse_integer.cpp
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
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      if (res > INT_MAX/10 || res < INT_MIN/10) {
	return 0;
      }
      res = res*10 + x%10;
      x /= 10;
    }
    return res;
  }
};
