/**
 *
 * File:    leetcode198/solution2.cpp
 *          打家劫舍
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/21
 *          
 **/


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int num1 = nums[0];
        int num2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int temp = num2;
            num2 = max(num2, num1 + nums[i]);
            num1 = temp;
        }
        return num2;
    }
};