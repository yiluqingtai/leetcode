/**
 *
 * File:    leetcode31.cpp
 *          下一个排列
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();

        // 找到第一个nums[i] < nums[i + 1]的元素，该元素及后面可重新排列
        int i = N - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 找到第一个nums[j] > nums[i]的元素，交换
        // i >= 0边界条件：如果已是最大排列，i为负数
        if (i >= 0) {
            int j = N - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[j], nums[i]);
        }

        // 交换后将后面序列递增排序（交换后后排序列必递减排序）
        reverse(nums.begin() + i + 1, nums.end());
    }
};