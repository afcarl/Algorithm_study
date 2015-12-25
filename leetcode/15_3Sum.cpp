/*
 * 15_3Sum.cpp
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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i=0;i<nums.size();++i) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      int target = nums[i];

      int head = i+1;
      int tail = nums.size() - 1;

      while (head < tail) {
	if (target + nums[head] + nums[tail] == 0) {
	  vector<int> sol;
	  sol.push_back(target);
	  sol.push_back(nums[head]);
	  sol.push_back(nums[tail]);
	  res.push_back(sol);
	  head += 1;
	  tail -= 1;
	  while(nums[head]==nums[head-1]) head++;
	  while(nums[tail]==nums[tail+1]) tail--;
	} else if (target + nums[head] + nums[tail] < 0) {
	  head += 1;
	} else {
	  tail -= 1;
	}
      }
    }
    return res;
  }
};
