//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// 关闭流同步
static int _ = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();

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

class Solution {
public:
    // 模拟搜索，只不过改成了迭代的形式(还有更好的解法,直接按层遍历)
    int maxDepth(Node* root) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }       
        queue<Node*> myQueue;
        map<Node*, int> myMap;
        myQueue.push(root);
        myMap[root] = 1;
        while (!myQueue.empty()) {
            Node* node = myQueue.front();
            myQueue.pop();
            if (depth < myMap[node]) {
                depth = myMap[node];
            }
            for (int i = 0; i < node->children.size(); i++) {
                myQueue.push(node->children[i]);
                myMap[node->children[i]] = myMap[node] + 1;
            }
        }
        return depth;
    }
    
    int maxDepth_better(Node* root) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }
        queue<Node*> myQueue;
        myQueue.push(root);
        // 一层一层的遍历树的结点(每多一层，深度就加一)
        while (!myQueue.empty()) {
            depth++;
            int n = myQueue.size();
            // 遍历当前层的结点，并将当前层的结点从队列中移除
            // 并将下一层的结点放入队列中
            for (int i = 0; i < n; i++) {
                Node* node = myQueue.front();
                myQueue.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    myQueue.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};

int main() {
    return 0;
}
