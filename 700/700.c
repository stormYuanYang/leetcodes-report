//MIT License
//Copyright (c) 2018 yangyuan
#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 使用中序遍历即可
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    struct TreeNode* a = searchBST(root->left, val);
    if (a) {
        return a;
    }
    struct TreeNode* b = searchBST(root->right, val);
    return b;
}

int main() {
    return 0;
}
