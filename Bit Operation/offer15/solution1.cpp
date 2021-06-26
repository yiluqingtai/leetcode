/**
 *
 * File:    offer15/solution1.cpp
 *          二进制中1的个数
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/6/23
 *          
 **/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1); // 非常规做法，这步操作去掉末尾的1
            ++res;
        }
        return res;
    }
};