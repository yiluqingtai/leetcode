/**
 *
 * File:    leetcode46.cpp
 *          全排列
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrace(res, temp, nums, used);
        return res;
    }

    void backtrace(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, 
             vector<bool> &used) {

        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                backtrace(res, temp, nums, used);
                used[i] = false;
                temp.pop_back();
            }
        }
    }
}; 