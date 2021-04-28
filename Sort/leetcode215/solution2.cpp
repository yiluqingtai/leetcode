/**
 *
 * File:    leetcode215/solution2.cpp
 *          数组中的第K个最大元素
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/28
 *          
 **/


class Solution {
public:
    /*堆排序*/
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        for (int i = N / 2; i >= 0; i--) sink(nums, i, N);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--N]);
            sink(nums, 0, N);
        }
        return nums[0];
    }

    void sink(vector<int>& nums, int i, int N) {
        while (2 * i + 1 < N) {
            int j = 2 * i + 1;
            if (j + 1 < N && nums[j + 1] > nums[j]) j++;
            if (nums[i] > nums[j]) break;
            swap(nums[i], nums[j]);
            i = j;
        }
    }
};