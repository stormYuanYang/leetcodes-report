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
    int smallestRangeI(vector<int>& A, int K) {
        int min = A[0], max = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (min > A[i]) {
                min = A[i];
            } else if (max < A[i]) {
                max = A[i];
            }
        }
        // 最小值加K和最大值减K的值无法相交
        if (max - min > K * 2) {
            return (max - K) - (min + K);
        } else {// 有交集
            return 0;
        }
    }
};

int main() {
    return 0;
}
