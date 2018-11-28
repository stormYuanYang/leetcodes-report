//MIT License
//Copyright (c) 2018 yangyuan
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

//static int desyncio = []() {
//    std::ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    return 0;
//}();

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int rowLen = A.size();
        int colLen = A[0].size();
        int count  = 0;
        for (int j = 0; j < colLen; j++) {
            for (int i = 0; i < rowLen - 1; i++) {
                if (A[i][j] > A[i+1][j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

#define YANGYUAN
int main() {
#ifdef YANGYUAN
    freopen("in.txt", "r", stdin);
#endif
    Solution slt;
    char str[1001];
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<string> A(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            A[i] = str;
        }
        int count = slt.minDeletionSize(A);
        printf("%d\n", count);
    }
    return 0;
}
