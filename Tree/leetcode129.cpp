/**
 *
 * File:    leetcode129.cpp
 *          求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

    void dfs(TreeNode *root, int &sum, int num) {
        if (!root) return;
        int temp = num;
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            sum += num;
        }
        dfs(root->left, sum, num);
        dfs(root->right, sum, num);
        num = temp;
    }
};