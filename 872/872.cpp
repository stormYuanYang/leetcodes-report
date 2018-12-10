//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 关闭流同步
static int _ = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    inline bool isLeafNode(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
    inline void pushChild2Stack(stack<TreeNode*> &s, TreeNode* node) {
        if (node->right) {
            s.push(node->right);
        }
        if (node->left) {
            s.push(node->left);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 一般深度遍历二叉树用递归实现比较简单，但是当树的结点
        // 数量比较多的时候，效率就不会很好，还可能会栈溢出
        // 所以用采用辅助数据结构stack，采用迭代的方式遍历二叉树
        stack<TreeNode*> stack1, stack2;
        stack1.push(root1);
        stack2.push(root2);
        while (!stack1.empty()) {
            TreeNode* node1 = stack1.top();
            stack1.pop();
            if (isLeafNode(node1)) {// 叶子结点
                if (stack2.empty()) {// root1还有叶子结点，但是root2的结点已经遍历完
                    return false;
                } else {
                    while (!stack2.empty()) {
                        TreeNode* node2 = stack2.top();
                        stack2.pop();
                        if (isLeafNode(node2)) {
                            if (node1->val != node2->val) {
                                return false; 
                            }
                            break;//已经找到一个叶子结点 跳出root2的叶子结点查找
                        } else {
                            pushChild2Stack(stack2, node2);
                        }
                    }         
                }
            } else {
                pushChild2Stack(stack1, node1);
            }
        }
        // 有可能root1的结点都遍历完了，但是root2还有结点
        // 注意，我们采用的是前序遍历(中左右)，也就是说root2还有结点的话
        // 那么必然还有叶子结点,也就是说root2和root1必然不是Leaf-Similar Trees
        if (stack2.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution slt;
    struct TreeNode a(2), b(1);
    cout << slt.leafSimilar(&a, &b) << endl;
    return 0;
}

