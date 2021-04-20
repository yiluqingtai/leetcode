/**
 *
 * File:    leetcode103.cpp
 *          二叉树的锯齿形层次遍历
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/20
 *          
 **/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int level = 0;
        while (!q.empty()) {
            int len = q.size();
            deque<int> dq;
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    dq.push_back(node->val);
                } else {
                    dq.push_front(node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.emplace_back(dq.begin(), dq.end());
            level++;
        }
        return res;
    }
};