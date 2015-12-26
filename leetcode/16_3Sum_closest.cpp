/*
 * 16_3Sum_closest.cpp
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
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int diff = INT_MAX; int res = diff;
    for (int i=0;i<nums.size()-2;++i) {
      int head = i + 1, tail = nums.size() - 1;
      if (i >= 1) {
	if (nums[i] == nums[i-1]) continue;
      }
      while (head < tail) {
	int sum = nums[i] + nums[head] + nums[tail];
	if (sum < target) {
	  if (target - sum < diff) {
	    diff = target - sum;
	    res = sum;
	  }
	  head++;
	  while (nums[head] == nums[head-1]) head++;
	} else {
	  if (sum - target < diff) {
	    diff = sum - target;
	    res = sum;
	  }
	  tail--;
	  while (nums[tail] == nums[tail+1]) tail--;
	}
      }
    }
    return res;
  }
};
