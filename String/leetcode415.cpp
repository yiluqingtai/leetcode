/**
 *
 * File:    leetcode415.cpp
 *          字符串相加
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
 *          
 **/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size() - 1, l2 = num2.size() - 1;
        string sumstr;
        int carry = 0;
        while (l1 >= 0 || l2 >= 0 || carry) {
            int a = l1 >= 0 ? num1[l1--] - '0' : 0;
            int b = l2 >= 0 ? num2[l2--] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            sumstr += sum % 10 + '0';
        }
        reverse(sumstr.begin(), sumstr.end());
        return sumstr;
    }
};