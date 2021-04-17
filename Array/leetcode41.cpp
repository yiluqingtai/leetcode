/**
 *
 * File:    leetcode41.cpp
 *          缺失的第一个正数
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();

        // 将负数变为下一步结果的N + 1
        for (int &num : nums) {
            if (num <= 0) {
                num = N + 1;
            }
        }

        // 数组元素为负数代表该元素的下标 + 1出现了
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (num >= 1 && num <= nums.size()) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // 搜寻第一个非负数
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return N + 1;
    }
};