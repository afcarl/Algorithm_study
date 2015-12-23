/*
 * 8_string_to_integer.cpp
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
  int myAtoi(string str) {
    int cnt = 0, res = 0;
    for (cnt=0; cnt<str.size(); ++cnt) {
      if (str[cnt] != ' ') break;
    }
    // if str is empty string
    if (cnt == str.size()) return 0;
    int sign = 0;

    if (str[cnt] == '+' || str[cnt] == '-') {
      sign = str[cnt] == '+' ? 1 : -1;
      cnt++;
    } else {
      sign = 1;
    }

    for (int i=cnt; i<str.size(); ++i) {
      if (str[i] >= '0' && str[i] <= '9') {
	if (res > INT_MAX / 10) {
	  return INT_MAX;
	} else if (res < INT_MIN / 10) {
	  return INT_MIN;
	} else {
	  if (i == cnt) {
	    res = sign * res * 10 + sign * (str[i] - '0');
	  } else {
	    if (sign == 1 && INT_MAX - res*10 < (str[i] - '0')) {
	      return INT_MAX;
	    } else if (sign == -1 && res < 0 && res*10 - INT_MIN < (str[i] - '0')) {
	      return INT_MIN;
	    }
	    res = res * 10 + sign * (str[i] - '0');
	  }
	}
      } else {
	break;
      }
    }
    return res;
  }
};
