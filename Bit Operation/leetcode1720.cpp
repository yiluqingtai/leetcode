/**
 *
 * File:    leetcode1720.cpp
 *          解码异或后的数组
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/6
 *          
 **/


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        /*找规律+利用异或的性质*/
        vector<int> res(encoded.size() + 1);
        res[0] = first;
        for (int i = 1; i < res.size(); i++) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
};