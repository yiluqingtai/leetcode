/**
 *
 * File:    leetcode3.cpp
 *          无重复字符的最长子串
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/20
 *          
 **/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*滑动窗口+哈希*/
        unordered_set<char> char_set;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            while (r < s.size() && char_set.find(s[r]) == char_set.end()) {
                res = max(res, r - l + 1);
                char_set.insert(s[r++]);
            }
            while (char_set.find(s[r]) != char_set.end()) {
                char_set.erase(s[l++]);
            }
        }
        return res;
    }
};