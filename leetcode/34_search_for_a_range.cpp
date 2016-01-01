class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> res;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target) {
	right = mid - 1;
      } else if (nums[mid] < target) {
	left = mid + 1;
      } else if (nums[mid] == target) {
	int l = mid, r = mid;
	for (int i=mid;i>=0 && nums[i] == target;--i) {
	  l = i;
	}
	for (int i=mid;i<nums.size() && nums[i] == target; ++i) {
	  r = i;
	}
	res.push_back(l);
	res.push_back(r);
	return res;
      }
    }
    res.push_back(-1);
    res.push_back(-1);
    return res;
  }
};
