//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
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
    set<Node*> mySet;
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        } 
        myStack.push(root);
        while (!myStack.empty()) {
            Node* pNode = myStack.top();
            // 是叶子节点，直接出栈
            if (pNode->children.empty()) {
                result.push_back(pNode->val);
                myStack.pop();
            } else {
                // 当结点被访问过，则当前结点出栈
                if (mySet.count(pNode) != 0) {
                    result.push_back(pNode->val);
                    myStack.pop();
                } else {
                    for (int i = pNode->children.size() - 1; i >= 0; i--) {
                        myStack.push(pNode->children[i]);
                    }
                }
            }
            // 标记当前结点已经被访问过
            mySet.insert(pNode);
        }
        return result;
    }
};

int main() {
    return 0;
}
