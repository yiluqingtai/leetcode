/**
 *
 * File:    leetcode54.cpp
 *          螺旋举着
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
 *          
 **/



class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m <= 0) return {};
        int n = matrix[0].size();
        if (n <= 0) return {};
        vector<int> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int len = m * n;
        int row = 0;
        int col = 0;
        int direction_index = 0;
        for (int i = 0; i < len; i++) {
            visited[row][col] = true;
            res.push_back(matrix[row][col]);
            int next_row = row + directions[direction_index][0];
            int next_col = col + directions[direction_index][1];
            if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n || visited[next_row][next_col]) {
                direction_index = (direction_index + 1) % 4;
            }
            row += directions[direction_index][0];
            col += directions[direction_index][1];
        }
        return res;
    }
};