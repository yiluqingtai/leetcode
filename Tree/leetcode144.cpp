/**
 *
 * File:    leetcode144.cpp
 *          二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> stk;
        vector<int> res;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};