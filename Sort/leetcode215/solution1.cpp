/**
 *
 * File:    leetcode215/solution1.cpp
 *          数组中的第K个最大元素
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/28
 *          
 **/


class Solution {
public:
    /*快速排序*/
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k);
    }

    int quick_sort(vector<int> &nums, int l, int r, int k) {
        if (l < r) {
            int m = partition(nums, l, r);
            if (m == nums.size() - k) {
                return nums[m];
            } else if (m > nums.size() - k) {
                return quick_sort(nums, l, m - 1, k);
            } else {
                return quick_sort(nums, m + 1, r, k);
            }
        } else {
            return nums[l];
        }
    }

    int partition(vector<int> &nums, int l, int r) {
        int p = nums[l];
        int lo = l, hi = r + 1;
        while (true) {
            while (nums[++lo] <= p) if (lo == r) break;
            while (nums[--hi] > p) if (hi == l) break;
            if (lo >= hi) break;
            swap(nums[lo], nums[hi]); 
        }
        swap(nums[l], nums[hi]);
        return hi;
    }
};