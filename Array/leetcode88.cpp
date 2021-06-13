/**
 *
 * File:    leetcode88.cpp
 *          合并两个有序数组
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
 *          
 **/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[l - 1] = nums2[n - 1];
                n--;
            } else {
                nums1[l - 1] = nums1[m - 1];
                m--;
            }
            l--;
        }
        while (n > 0) {
            nums1[l - 1] = nums2[n - 1];
            l--;
            n--;
        }
    }
};