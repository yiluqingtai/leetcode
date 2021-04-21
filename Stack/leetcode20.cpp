/**
 *
 * File:    leetcode20.cpp
 *          有效的括号
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/20
 *          
 **/



class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> dict = {{')', '('}, {']', '['}, {'}', '{'}};
        for (int i = 0; i < s.size(); i++) {
            if (dict.find(s[i]) != dict.end()) {
                if (stk.empty() || stk.top() != dict[s[i]]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};