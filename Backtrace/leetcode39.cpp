/**
 *
 * File:    leetcode39.cpp
 *          组合总数
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(res, temp, candidates, target, 0);
        return res;
    }

    void backtrace(vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, 
             int target, int begin) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = begin; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrace(res, temp, candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
};