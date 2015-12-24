/*
 * 9_palindrome_number.cpp
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
  bool isPalindrome(int x) {
    if (x < 0) return false;

    int digit = 1;
    while (x / digit >= 10) {
      digit *= 10;
    }

    while (x != 0) {
      int head = x / digit;
      int tail = x % 10;
      if (head != tail) {
	return false;
      } else {
	x = (x % digit) / 10;
	digit /= 100;
      }
    }
    return true;
  }
};
