/**
 *
 * File:    leetcode121.cpp
 *          买卖股票的最佳时机
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/29
 *          
 **/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            min_val = min(min_val, prices[i]);
            res = max(res, prices[i] - min_val);
        }
        return res;
    }
};