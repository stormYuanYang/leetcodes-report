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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rowLen = A.size();
        int colLen = A[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < colLen; i++) {
            vector<int> one;
            for (int j = 0; j < rowLen; j++) {
                one.push_back(A[j][i]);
            }
            result.push_back(one);
        }
        return result;
    }
};

int main() {
    return 0;
}
