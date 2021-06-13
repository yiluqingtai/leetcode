/**
 *
 * File:    leetcode113cpp
 *          路径总和2
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, root, targetSum);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &temp, TreeNode* root, int targetSum) {
        if (!root) return;
        temp.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0) res.push_back(temp);
        dfs(res, temp, root->left, targetSum);
        dfs(res, temp, root->right, targetSum);
        temp.pop_back();
    }
};