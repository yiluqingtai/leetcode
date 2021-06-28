/**
 *
 * File:    leetcode815.cpp
 *          公交路线
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
 *          
 **/



class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        // 建立连接图，图的顶点是公交路线，如果可以两个公交路线间可以换乘，则连接两点
        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> route_vec;
        for (int i = 0; i < routes.size(); i++) {
            for (int site : routes[i]) {
                for (int j : route_vec[site]) {
                    edge[i][j] = edge[j][i] = 1;
                }
                route_vec[site].push_back(i);                
            }
        }

        // 将包含初始站点的所有公交路线加入到队列中
        queue<int> q;
        vector<int> dis(n, -1);
        for (int route : route_vec[source]) {
            q.push(route);
            dis[route] = 1; 
        }

        // BFS，每搜索一次距离加一，保存当前节点和源节点的距离值
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (edge[i][j] && dis[j] == -1) {
                    dis[j] = dis[i] + 1; 
                    q.push(j);
                }
            }
        }

        // 对于每个目的节点，获取其最小连接边数量
        int ret = INT_MAX;
        for (int route : route_vec[target]) {
            ret = min(ret, dis[route]);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};