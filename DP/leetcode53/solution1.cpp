/**
 *
 * File:    leetcode53/solution1.cpp
 *          最大子序和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/6
 *          
 **/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*传统dp，递推过程中更新res*/
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};