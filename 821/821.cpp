//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
#include <vector>
using namespace std;

// 关闭流同步
static int _ = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();

class Solution {
public:
    // 用二分搜索（还有更好的解法）
    vector<int> shortestToChar(string S, char C) {
        vector<int> A;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                A.push_back(i);
            }
        }
        vector<int> result(S.size());
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                result[i] = 0;
            } else {
                int first = 0;
                int mid   = 0;
                int last  = A.size() - 1;
                while (first <= last) {
                    mid = first + ((last - first) >> 1);
                    if (i == A[mid]) {
                        break;
                    } else if (i < A[mid]) {
                        last = mid - 1;
                    } else {
                        first = mid + 1;
                    }
                } 

                if (i == A[mid]) {
                    result[i] = 0;
                } else {
                    // 逻辑走到这里，一定有last + 1 == first
                    if (last < 0) {
                        result[i] = A[0] - i;
                    } else if (first > A.size() - 1) {
                        result[i] = i - A[A.size() - 1];
                    } else {
                        int leftLen = i - A[last];
                        int rightLen = A[first] - i;
                        result[i] = (leftLen < rightLen) ? leftLen : rightLen;
                    }
                }
            }
        }
        return result;
    }
};
int main() {
    char S[] = "loveleetcode";
    char C = 'e';
    Solution slt;
    vector<int> result = slt.shortestToChar(S, C);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
