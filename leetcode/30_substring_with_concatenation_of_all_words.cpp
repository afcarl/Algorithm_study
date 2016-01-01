class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> table;

    for (int i = 0; i<words.size(); ++i) {
      if (table.count(words[i])) {
	table[words[i]] += 1;
      }
      else {
	table.insert(make_pair(words[i], 1));
      }
    }

    vector<int> result;
    if (words.size() == 0) return result;

    int word_length = words[0].size();
    for (int i = 0; i<word_length; ++i) {
      unordered_map<string, int> record;
      int cnt = 0, left = i;
      for (int j = i; j + word_length<=s.size(); j += word_length) {
	string cur_str = s.substr(j, word_length);
	if (table.count(cur_str)) {
	  if (record.count(cur_str)) {
	    record[cur_str] += 1;
	  } else {
	    record[cur_str] = 1;
	  }

	  if (record[cur_str] <= table[cur_str]) {
	    cnt++;
	  } else {
	    for (int k = left; ; k += word_length)
	      {
		string tmpstr = s.substr(k, word_length);
		record[tmpstr]--;
		if (tmpstr == cur_str)
		  {
		    left = k + word_length;
		    break;
		  }
		cnt--;
	      }
	  }

	  if (cnt == words.size()) {
	    result.push_back(left);
	  }
	}
	else {
	  record.clear();
	  left = j + word_length;
	  cnt = 0;
	}
      }
    }
    return result;
  }
};
