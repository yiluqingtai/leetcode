/**
 *
 * File:    leetcode69.cpp
 *          x的平方根
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    /*二分查找*/
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((long long) m * m <= x) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};