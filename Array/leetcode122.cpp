/**
 *
 * File:    leetcode122.cpp
 *          买卖股票的最佳时机2
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            res += max(0, prices[i + 1] - prices[i]);
        }
        return res;
    }
};