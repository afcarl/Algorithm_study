/*
 * 42_trapping_rain_water.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2016 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 * 
 * You may find corresponding tutorial at:
 * https://oh233.github.io/Algorithm_study/leetcode.html
 */

class Solution {
public:
  int trap(vector<int>& height) {
    int max_val = -1;
    int max_id = -1;
    // get highest element
    for (int i = 0; i < height.size(); ++i) {
      if (height[i] > max_val) {
        max_val = height[i];
        max_id = i;
      }
    }
    int area = 0, prev_height = 0;
    for (int i = 0; i < max_id; ++i) {
      if (height[i] >= prev_height) {
        prev_height = height[i];
      } else {
        area += (prev_height - height[i]);
      }
    }
    prev_height = 0;
    for (int i = height.size() - 1; i > max_id; --i) {
      if (height[i] >= prev_height) {
        prev_height = height[i];
      } else {
        area += (prev_height - height[i]);
      }
    }
    return area;
  }
};
