//MIT License
//Copyright (c) 2018 yangyuan
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int length = 0;
    for (; S[length] != '\0'; length++) {}
    *returnSize = length + 1;
    int* result = (int*)malloc(sizeof(int) * *returnSize);
    int a = 0, b = length;
    for (int j = 0; j < length; j++) {
        if (S[j] == 'D') {
            result[j] = b--;
        } else {
            result[j] = a++;
        }
    }
    result[length] = a;
    return result;
}
int main() {
    int resultSize = 0;
    int* result = diStringMatch("DIDDDII", &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
