/**
 *
 * File:    leetcode33.cpp
 *          搜索旋转排序数组
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/4
 *          
 **/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*二分查找*/
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) {
                return m;
            } else {
                if (nums[l] <= nums[m]) {
                    if (target >= nums[l] && target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if (target > nums[m] && target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }
        return -1;
    }
};