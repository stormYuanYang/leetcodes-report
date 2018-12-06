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
    vector<int> numberOfLines(vector<int>& widths, string S) {
        // 至少占一行，所以line初始化为1
        int line = 1, len = 0;
        for (int i = 0; i < S.size(); i++) {
            len += widths[S[i] - 'a'];
            // 超出当前行，需要换行
            if (len > 100) {
                len = widths[S[i] - 'a'];
                line++;//有新行，line增加
            }
        }      
        vector<int> result;
        result.push_back(line);
        result.push_back(len);
        return result;
    }
};

int main() {
    return 0;
}
