/**
 *
 * File:    leetcode101.cpp
 *          对称二叉树
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/17
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return fun(root->left, root->right);
    }

    bool fun(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val &&fun(left->left, right->right) && 
               fun(left->right, right->left);
    }
};