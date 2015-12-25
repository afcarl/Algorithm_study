/*
 * 10_regular_expression_matching.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2015/12/23/LeetCode-Report-6-10/
 */

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;

    for (int j=2;j<=n;j++) {
      if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }

    for (int i=1; i<=m; ++i) {
      for (int j=1; j<=n; ++j) {
	if (p[j-1] != '*' && p[j-1] != '.') {
	  // normal character
	  dp[i][j] = (dp[i-1][j-1] && s[i-1] == p[j-1]);
	} else if (p[j-1] == '.') {
	  // dot character
	  dp[i][j] = dp[i-1][j-1];
	} else if (j >= 2) {
	  // star character
	  dp[i][j] =
	    (dp[i][j-1]) || // matching one precedent
	    (dp[i][j-2]) || // matching zero precedent
	    ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]); // matching multiple precedent
	}
      }
    }
    return dp[m][n];
  }
};
