/**
 *
 * File:    offer15.solution2.cpp
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
        for (int i = 0; i < 32; i++) {
            res += (n & (1 << i)) == 0 ? 0 : 1;
        }
        return res;
    }
};