/**
 *
 * File:    leetcode773.cpp
 *          滑动谜题
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/



class Solution {
public:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int slidingPuzzle(vector<vector<int>>& board) {
        string initial;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                initial.push_back(board[i][j] + '0');
            }
        }

        if (initial == "123450") {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.emplace(initial, 0);
        unordered_set<string> seen;
        seen.insert(initial);

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (string next_status : get(status)) {
                if(seen.find(next_status) == seen.end()) {
                    if (next_status == "123450") {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(next_status);
                }
            }
        }

        return -1;
    }

    vector<string> get(string s) {
        vector<string> res;
        int x = s.find('0');
        for (int y : neighbors[x]) {
            swap(s[x], s[y]);
            res.push_back(s);
            swap(s[x], s[y]);
        }
        return res;
    }
};  