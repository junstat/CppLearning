// PAT Advance Level 1002
// Ye Qiu
#include <iostream>
#include <string>

using namespace std;

/*
    定义数组保存结果，依次读入A, B行，指数为下标，系数为值累加到结果数组中
 */
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1002.txt", "r", stdin);
#endif
    float result[1001] = {0};
    int kA, kB, power;
    float coefficient;
    scanf("%d", &kA);
    for (int i = 0; i < kA; i++) {
        scanf("%d%f", &power, &coefficient);
        result[power] += coefficient;
    }
    scanf("%d", &kB);
    for (int i = 0; i < kB; i++) {
        scanf("%d%f", &power, &coefficient);
        result[power] += coefficient;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (result[i]) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (result[i] != 0.0)
            printf(" %d %.1f", i, result[i]);
    }
    return 0;
}
