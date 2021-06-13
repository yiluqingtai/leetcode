/**
 *
 * File:    leetcode5/solution2.cpp
 *          最长回文子串
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
 *          
 **/


class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        int len = 1, left = 0;
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i < N - l + 1; i++) {
                int j = i + l - 1;
                if (l == 1) dp[i][j] = true;
                else if (l == 2) dp[i][j] = s[i] == s[j];
                else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }
                if (dp[i][j] && l > len) {
                    len = l;
                    left = i;
                }
            }
        }
        return s.substr(left, len);
    }
};