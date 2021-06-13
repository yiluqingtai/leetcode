/**
 *
 * File:    leetcode5/solution1.cpp
 *          最长回文子串
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
 *          
 **/


class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int left = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            auto [left1, right1] = palindrome(s, i, i);
            auto [left2, right2] = palindrome(s, i, i + 1);
            if (right1 - left1 + 1 > len) {
                left = left1;
                len = right1 - left1 + 1;
            }
            if (right2 - left2 + 1 > len) {
                left = left2;
                len = right2 - left2 + 1;
            }
        }
        return s.substr(left, len);
    }

    pair<int, int> palindrome(string &s, int l, int r) {
        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l + 1, r - 1};
    }
};