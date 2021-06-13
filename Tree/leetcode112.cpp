/**
 *
 * File:    leetcode112.cpp
 *          路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right && targetSum == root->val) return true;
        return hasPathSum(root->left, targetSum - root->val) 
                          || hasPathSum(root->right, targetSum - root->val);
    }
};