/**
 *
 * File:    leetcode236.cpp
 *          二叉树的最近公共祖先
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/4
 *          
 **/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};