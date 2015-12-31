class Solution {
public:
  int strStr(string haystack, string needle) {
    return KmpSearch(haystack, needle);
  }

private:

  int KmpSearch(string s, string p)
  {
    vector<int> lps = getLps(p);
    int i = 0, j = 0;
    int sLen = s.size(), pLen = p.size();
    while (i < sLen && j < pLen) {
      if (j == -1 || s[i] == p[j]) {
	i++;
	j++;
      }
      else {
	j = lps[j];
      }
    }
    if (j == pLen) {
      return i - j;
    } else {
      return -1;
    }
  }

  vector<int> getLps(string p) {
    vector<int> res;
    res.push_back(-1);
    int k = -1, j = 0;
    int pLen = p.size();
    while (j < pLen - 1) {
      if (k == -1 || p[j] == p[k]) {
	j++; k++;
	int val = p[j] != p[k] ? k : res[k];

	if (res.size() == j + 1) {
	  res[j] = val;
	} else {
	  res.push_back(val);
	}
      }
      else {
	k = res[k];
      }
    }
    return res;
  }
};
