/**
 *
 * File:    leetcode1835/solution2.cpp
 *          所有数按位与结果的异或和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/19
 *          
 **/


class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        /*利用异或和与的分配律特点*/
        int cnt1 = 0, cnt2 = 0;
        for (int num : arr1) {
            cnt1 ^= num;
        }
        for (int num : arr2) {
            cnt2 ^= num;
        }
        return cnt1&cnt2;
    }
};