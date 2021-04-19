/**
 *
 * File:    leetcode5735.cpp
 *          雪糕的最大数量
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/18
 *          
 **/


class Solution {
public:
    /*贪心*/
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int cost : costs) {
            if (coins < cost) return res;
            coins -= cost;
            res++;
        }
        return res;
    }
};