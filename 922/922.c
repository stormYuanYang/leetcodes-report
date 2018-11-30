//MIT License
//Copyright (c) 2018 yangyuan
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* result = (int*)malloc(sizeof(int) * ASize);
    int evenIndex = 0, oddIndex = 1;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 1) == 0) {
            result[evenIndex] = A[i];
            evenIndex += 2;
        } else {
            result[oddIndex] = A[i];
            oddIndex += 2;
        }
    }
    return result;
}
int main() {
    int A[] = {4,2,5,7};
    int returnSize;
    int* result = sortArrayByParityII(A, sizeof(A) / sizeof(int), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\nreturnSize:%d\n", returnSize);
    return 0;
}
