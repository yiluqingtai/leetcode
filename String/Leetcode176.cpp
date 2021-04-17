/**
 *
 * File:    leetcode176.cpp
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
        for (char c : t) {
            dict[c]++;
        }
        int count = t.size();
        int l = 0, r = 0;
        int start = 0, len = INT_MAX;
        while (r < s.size()) {
            // dict[s[r]] > 0 这个判断条件：已不存在于t的字符小于等于0
            if (dict[s[r]] > 0) {
                count--;
            }
            dict[s[r]]--;
            if (count == 0) {
                while (l <= r && dict[s[l]] < 0) {
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
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};