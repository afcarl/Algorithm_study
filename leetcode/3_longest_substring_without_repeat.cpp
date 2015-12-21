/*
* 3_longest_substring_without_repeat.cpp
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
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_set<char> table;
        for (int i = 0, j = 0; j < s.size(); j++)
        {
            if (table.count(s[j])) {
                while (i < j & s[i] != s[j])
                {
                    table.erase(s[i]);
                    i++;
                }
                table.erase(s[i]); i++;
            }
            table.insert(s[j]);
            result = max(result, (int) table.size());
        }
        return result;
    }
};
