//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
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
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head; 
        // p1一次走一步
        // p2一次走两步
        while (p2) {
            p2 = p2->next;
            if (p2 == nullptr) {
                break;
            }
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};

int main() {
    return 0;
}
