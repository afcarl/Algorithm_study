/*
 * 10_regular_expression_matching.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2016 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 */

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> items;
    _dfs(candidates, target, 0, items);
    return result;
  }
    
private:
  void _dfs(const vector<int>& candidates, int target, int start, vector<int>& items) {
    for (int i = start; i < candidates.size(); ++i) {
      if (i > start && candidates[i] == candidates[i-1]) continue;
      if (candidates[i] > target) break;
      if (candidates[i] == target) {
        items.push_back(candidates[i]);
        result.push_back(items);
        items.pop_back();
      } else if (candidates[i] < target) {
        items.push_back(candidates[i]);
        _dfs(candidates, target - candidates[i], i, items);
        items.pop_back();
      }
    }
  }
  vector<vector<int>> result;
};
