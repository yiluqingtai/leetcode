/**
 *
 * File:    leetcode56.cpp
 *          合并区间
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            if (!res.empty() && res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        return res;
    }
};