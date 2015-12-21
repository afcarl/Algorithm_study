/*
 * 4_median_of_two_sorted_arrays.capp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/11/29/Leetcode-Report/
 */

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int total = n + m;
    if (total % 2 == 1) {
      return findKthSmallest(nums1, nums2, total / 2 + 1);
    }
    else {
      return (findKthSmallest(nums1, nums2, total / 2 + 1) +
	      findKthSmallest(nums1, nums2, total / 2)) / 2;
    }
  }
  
  double findKthSmallest(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    // assume n is always smaller or equal to m to avoid boundary case
    if (n > m) {
      return findKthSmallest(nums2, nums1, k);
    }
    if (n == 0) {
      return nums2[k - 1];
    }
    if (k == 1) {
      return min(nums1[0], nums2[0]);
    }
    int part_s1 = min(k / 2, n); int part_s2 = k - part_s1;
    int median_s1 = nums1[part_s1 - 1];
    int median_s2 = nums2[part_s2 - 1];
    if (median_s1 < median_s2) {
      // discard nums1[1...part_s1]
      vector<int> tmp(nums1.begin() + part_s1, nums1.end());
      return findKthSmallest(tmp, nums2, k - part_s1);
    }
    else if (median_s1 > median_s2) {
      // discard nums2[1...part_s2]
      vector<int> tmp(nums2.begin() + part_s2, nums2.end());
      return findKthSmallest(nums1, tmp, k - part_s2);
    }
    else {
      return median_s1;
    }
  }
};
