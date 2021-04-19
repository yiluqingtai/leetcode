/**
 *
 * File:    leetcode5736.cpp
 *          单线程CPU
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/18
 *          
 **/


class Solution {
public:
    /*优先级队列*/
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int N = tasks.size();
        vector<int> index(N);
        for (int i = 0; i < N; i++) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long time = 0;
        vector<int> res;
        int ptr = 0;
        for (int i = 0; i < N; i++) {
            if (pq.empty()) {
                time = max(time, (long long)tasks[index[ptr]][0]);
            }
            while (ptr < N && tasks[index[ptr]][0] <= time) {
                pq.push({tasks[index[ptr]][1], index[ptr]});
                ptr++;
            }
            auto [pro_time, ind] = pq.top();
            pq.pop();
            res.push_back(ind);
            time += pro_time;
        }
        return res;
    }
};