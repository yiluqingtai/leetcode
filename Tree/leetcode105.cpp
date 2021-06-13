/**
 *
 * File:    leetcode105.cpp
 *          从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> dict;
        for (int i = 0; i < inorder.size(); i++) {
            dict[inorder[i]] = i;
        }
        return construct(preorder, inorder, dict, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *construct(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &dict,
                        int preorder_left, int preorder_right,
                        int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        int index = dict[preorder[preorder_left]];
        TreeNode *node = new TreeNode(inorder[index]);
        node->left = construct(preorder, inorder, dict, preorder_left + 1,
                               preorder_left + index - inorder_left,
                               inorder_left, index - 1);
        node->right = construct(preorder, inorder, dict, preorder_left + index -inorder_left + 1,
                                preorder_right, index + 1, inorder_right);
        return node;
    }
};