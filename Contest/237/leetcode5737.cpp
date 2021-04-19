/**
 *
 * File:    leetcode5737.cpp
 *          判断句子是否为全字母句
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/18
 *          
 **/


class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> char_set; 
        for (char &c : sentence) {
            char_set.insert(c);
        }
        return char_set.size() == 26;
    }
};