#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int x, y, maxVal;
    // 定义函数指针
    int (*pmax)(int, int) = max;
    printf("Input two number:");
    scanf("%d %d", &x, &y);
    maxVal = pmax(x, y);
    printf("Max value: %d\n", maxVal);
    return 0;
}