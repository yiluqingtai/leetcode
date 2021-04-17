/**
 *
 * File:    leetcode300.cpp
 *          最长上升子序列
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};