//MIT License
//Copyright (c) 2018 yangyuan
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// 关闭流同步
static int _ = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();

class Solution {
public:
    // 用二分搜索找到最高位/直接用库函数求num关于2的对数
    int findComplement(int num) {
        // len == 最高位1的位置+1
        int len = floor(log2(num)) + 1;
        // 如果len等于int的总位数，那么对于有符号整数来说
        // (1 << len)的结果必然是int的最小值,
        // 但这样是没问题的，((1 << len)-1)依然能得到正确结果
        return ((1 << len) - 1) ^ num;
    }

    //遍历找到最高位1
    int findComplement1(int num) {
        int i = 30;
        for (; i >= 0; i--) {
            if (num >> i) {
                break;
            }
        }
        for (int j = i; j >= 0; j--) {
            // 1变0, 0变1
            num ^= (1 << j);
        }
        return num;
    }
};

int main() {
    Solution slt;
    cout << slt.findComplement(5) << endl;
    cout << slt.findComplement(INT_MAX) << endl;
    cout << INT_MAX << endl;
    return 0;
}
