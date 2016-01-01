
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int i;
    for (i=nums.size() - 1;i>=1;--i) {
      if (nums[i] <= nums[i-1]) {
	continue;
      } else {
	_swap(i-1, nums);
	break;
      }
    }
    sort(nums.begin()+i, nums.end());
  }

private:
  void _swap(int ind, vector<int>& nums) {
    int res = INT_MAX;
    int res_ind = ind;
    for (int i=ind+1;i<nums.size();++i) {
      if (nums[i] > nums[ind] && nums[i] < res) {
	res = nums[i];
	res_ind = i;
      }
    }
    int tmp = nums[ind];
    nums[ind] = nums[res_ind];
    nums[res_ind] = tmp;
  }
};
