/**
 *
 * File:    leetcode98.cpp
 *          验证二叉搜索树
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/21
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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode *root) {
        if (!root) return true;
        bool left = inorder(root->left);
        if (root->val <= pre) return false;
        pre = root->val;
        bool right = inorder(root->right);
        return left && right;
    }
};