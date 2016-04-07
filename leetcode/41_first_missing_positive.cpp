/*
 * 41_first_missing_positive.cpp
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
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 1 || nums[i] > nums.size()) continue;
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
        i -= 1;
      }
    }
    int res = nums.size() + 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        res = i + 1;
        break;
      }
    }
    return res;
  }
};
