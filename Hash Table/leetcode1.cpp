/**
 *
 * File:    leetcode1.cpp
 *          两数之和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(target - nums[i]) != dict.end()) {
                return {i, dict[target - nums[i]]};
            } else {
                dict.insert({nums[i], i});
            }
        }
        return {};
    }
};