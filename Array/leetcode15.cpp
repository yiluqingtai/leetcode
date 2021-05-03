/**
 *
 * File:    leetcode15.cpp
 *          三数之和
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/3
 *          
 **/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < N; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                while (l > i + 1 && l < r && nums[l] == nums[l - 1]) l++;
                while (r < N - 1 && l < r && nums[r] == nums[r + 1]) r--;
                if (l == r) break;
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};