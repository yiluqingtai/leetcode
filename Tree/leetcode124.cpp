/**
 *
 * File:    leetcode124.cpp
 *          二叉树中的最大路径和
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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        fun(root);
        return res;
    }

    /*递归的子结构不是要求的结果，要求的最大路径和在递归的过程中计算*/
    int fun(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, fun(root->left));
        int right = max(0, fun(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};