/*
 * 11_container_with_most_water.cpp
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
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int res = 0;
    while (i < j) {
      int h = min(height[i], height[j]);
      res = (h * (j-i)) > res ? h*(j-i) : res;
      if (height[i] > height[j]) j--;
      else i++;
    }
    return res;
  }
};
