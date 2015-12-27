/*
 * 18_4Sum.cpp
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

class MyHash
{
public:
  std::size_t operator()(const vector<int> &v) const
  {
    std::size_t x = 0;
    for (auto &i : v)
      x ^= std::hash<int>()(i);
    return x;
  }
};

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<pair<node, node> > table;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
	table.push_back(make_pair(node(i, nums[i]), node(j, nums[j])));
      }
    }
    sort(table.begin(), table.end(), pair_compare);
    unordered_set<vector<int>, MyHash> solution_set;
    vector<int> solution;
    int head = 0, tail = table.size() - 1;
    while (head < tail) {

      if (cal_target(table[head], table[tail]) < target) {
	head++;
      }
      else if (cal_target(table[head], table[tail]) > target) {
	tail--;
      }
      else {

	int lEnd = head;
	int rEnd = tail;
	while(lEnd < rEnd && cal_sum(table[lEnd])==cal_sum(table[lEnd+1])) {
	  lEnd++;
	}
	while(lEnd < rEnd && cal_sum(table[rEnd])==cal_sum(table[rEnd-1])) {
	  rEnd--;
	}
	for(int i=head;i<=lEnd;i++) {
	  for(int j=tail;j>=rEnd;j--) {

	    if(!intersect(table[i], table[j])) {
	      solution.push_back(table[i].first.val);
	      solution.push_back(table[i].second.val);
	      solution.push_back(table[j].first.val);
	      solution.push_back(table[j].second.val);
	      sort(solution.begin(), solution.end());
	      solution_set.insert(solution);
	      solution.clear();
	    }
	  }
	}
	head = lEnd + 1;
	tail = rEnd - 1;
      }

    }
    return std::vector<vector<int>>(solution_set.begin(), solution_set.end());
  }
private:
  struct node {
    node(int i, int v) : ind(i), val(v) {}
    int ind;
    int val;
  };

  static bool pair_compare(pair<node, node> l, pair<node, node> r) {
    return l.first.val + l.second.val < r.first.val + r.second.val;
  }

  bool intersect(pair<node, node> l, pair<node, node> r) {
    if (l.first.ind == r.first.ind || l.first.ind == r.second.ind
	|| l.second.ind == r.first.ind || l.second.ind == r.second.ind) {
      return true;
    }
    else {
      return false;
    }
  }

  int cal_target(pair<node, node> l, pair<node, node> r) {
    return l.first.val + l.second.val + r.first.val + r.second.val;
  }

  int cal_sum(pair<node, node> param) {
    return param.first.val + param.second.val;
  }
};
