#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10010;

int A[maxn], dp[maxn]; // A[i]存放序列，dp[i]存放以A[i]结尾的连续序列的最大和

int main() {
    freopen("./input/nums.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    // 边界
    dp[0] = A[0];
    int k = 0;
    for (int i = 1; i < n; i++) {
        // 状态转移方程
        dp[i] = max(dp[i - 1] + A[i], A[i]);
        // dp[i] 存放以A[i]结尾的连续序列的最大和，需要遍历i得到最大的才是结果
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}