/**
 *
 * File:    leetcode98.cpp
 *          验证二叉搜索树
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/22
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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (pre && root->val <= pre->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};