/**
 *
 * File:    leetcode76.cpp
 *          最小覆盖子串
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for (char &c : t) {
            dict[c]++;
        }

        int count = t.size();

        int len = s.size() + 1, start = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (dict[s[r]] > 0) {
                count--;
            }
            dict[s[r]]--;

            if (count == 0) {
                while (dict[s[l]] < 0) {
                    dict[s[l++]]++;
                }
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
                dict[s[l]]++;
                l++;
                count++;
            }
            r++;
        }

        return len > s.size() ? "" : s.substr(start, len);
    }
};