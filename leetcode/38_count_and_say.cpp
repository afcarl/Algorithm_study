/*
 * 38_count_and_say.cpp
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 *
 * You may find the solution tutorial in
 * http://oh233.github.io/2016/01/01/LeetCode-Report-31-40/
 */

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (n > 1) {
            string tmp = "";
            int cnt = 1;
            for (int i = 0; i < res.size(); ++i) {
                if (i == res.size() || res[i] != res[i+1]) {
                    tmp = tmp + (char) (cnt + '0') + res[i];
                    cnt = 0;
                } else {
                    cnt += 1;
                    continue;
                }
            }
            res = tmp;
            n -= 1;
        }
        return res;
    }
};