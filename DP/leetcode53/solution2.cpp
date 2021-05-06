/**
 *
 * File:    leetcode53/solution2.cpp
 *          最大子序和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/6
 *          
 **/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*优化后的dp，每个状态只和前一个状态有关*/
        int pre = 0, cur = nums[0];
        for (int num : nums) {
            pre = max(num, pre + num);
            cur = max(cur, pre);
        }
        return cur;
    }
};