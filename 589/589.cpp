#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {
    }

    Node(int _val, vector<Node*> _children) {
        val      = _val;
        children = _children;
    }
};
// 关闭流同步
static int _ = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();
class Solution {
public:
    stack<Node*> myStack;
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        // 为避免递归，使用迭代的方式遍历树的节点
        // 实际上这种前序遍历的迭代实现方式本质上是deep first search
        myStack.push(root);
        while (!myStack.empty()) {
            Node* node = myStack.top();
            result.push_back(node->val);
            myStack.pop();
            for (int i = node->children.size() - 1; i >= 0; i--) {
                myStack.push(node->children[i]);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
