/**
 *
 * File:    leetcode42/solution2.cpp
 *          接雨水
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/4
 *          
 **/

class Solution {
public:
    int trap(vector<int>& height) {
        /*双指针*/
        int N = height.size();
        if (N < 1) return 0;
        int left = 0, right = N - 1;
        int res = 0;
        int left_max = height[0];
        int right_max = height[N - 1];
        while (left <= right) {
            if (left_max < right_max) {
                res += max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left++;
            } else {
                res += max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right--;
            }
        }
        return res;
    }
};