/**
 *
 * File:    leetcode1835/solution1.cpp
 *          所有数按位与结果的异或和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/19
 *          
 **/



class Solution {
public:
    /*异或和：所有元素的该位1的个数为奇数，那么结果为1，否则为0*/
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for (int k = 30; k >= 0; k--) {
            int cnt1 = 0, cnt2 = 0;
            for (int num : arr1) {
                if (num & (1 << k)) {
                    cnt1++;
                }
            }
            for (int num : arr2) {
                if (num & (1 << k)) {
                    cnt2++;
                }
            }
            if (cnt1 % 2 != 0 && cnt2 % 2 != 0) {
                ans |= 1 << k;
            }
        }
        return ans;
    }
};