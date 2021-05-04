/**
 *
 * File:    leetcode42/solution1.cpp
 *          接雨水
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/4
 *          
 **/


class Solution {
public:
    int trap(vector<int>& height) {
        /*动态规划*/
        int N = height.size();
        if (N < 1) return 0;
        vector<int> left_max(N, 0);
        vector<int> right_max(N, 0);
        left_max[0] = height[0];
        right_max[N - 1] = height[N - 1]; 
        for (int i = 1; i < N; i++)
            left_max[i] = max(left_max[i - 1], height[i]);
        for (int i = N - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], height[i]);
        int res = 0;
        for (int i = 0; i < N; i++)
            res += min(left_max[i], right_max[i]) - height[i];
        return res;
    }
};

