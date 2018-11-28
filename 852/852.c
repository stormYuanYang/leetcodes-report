//MIT License
//Copyright (c) 2018 yangyuan
#include <stdio.h>
//A[x-1] < A[x] > A[x+1]
//不需要考虑x==0或x==ASize-1的的情况
//因为题目保证至少有3个元素
int peakIndexInMountainArray(int* A, int ASize) {
    int first = 0;
    int last  = ASize - 1;
    int mid   = -1;
    while (first <= last) {
        mid = first + ((last - first) >> 1);
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
            break;
        }
        if (A[mid] < A[mid - 1]) {
            last = mid - 1; 
        } else {
            first = mid + 1;
        }
    }
    return mid;
}

int A[10000];

#define YANGYUAN
int main() {
#ifdef YANGYUAN
    freopen("in.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        int index = peakIndexInMountainArray(A, n);
        printf("index:%d\n", index);
    }
    return 0;
}
