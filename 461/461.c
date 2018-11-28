//MIT License
//Copyright (c) 2018 yangyuan
#include <stdio.h>
#include <limits.h>

// 如果需要考虑int范围问题，则用宏判断一下用UINT类型
//#if UINT_MAX == 65535
//    #define UINT long unsigned
//#endif
//    #define UINT unsigned

// 这是leetecode给的接口口,那应该就是不用考虑int的范围问题
int hammingDistance(int x, int y) {
    int a = x ^ y;
    int count = 0;
    while (a != 0) {
        a &= a - 1;//将最右端的1到最低位的所有位全都置为0
        count++; 
    }
    return count;    
}

#define YANGYUAN
int main() {
#ifdef YANGYUAN
    freopen("in.txt", "r", stdin);
#endif
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", hammingDistance(a, b));
    }
    return 0;
}
