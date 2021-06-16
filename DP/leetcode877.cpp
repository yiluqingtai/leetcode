/**
 *
 * File:    leetcode877.cpp
 *          石子游戏
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/6/16
 *          
 **/



class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
        }
        // dp[i][j]表示在i和j之间的石子中拿时亚历克斯所能拿到的最大值
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i < N - l + 1; i++) {
                int j = i + l - 1;
                if (l == 1) {
                    dp[i][j] = 0;
                } else if (l % 2 == 1) { // 表示李拿
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                } else {    // 表示亚历克斯拿
                    dp[i][j] = max(dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]);
                }
            }
        }
        return dp[0][N - 1] > sum / 2;
    }
};