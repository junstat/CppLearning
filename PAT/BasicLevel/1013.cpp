//
// @Time   : 2021/1/14 20:35
// @Author : junstat@163.com

#include "BasicLevel.h"

/*
   1. 素数判断
   2. num in [2, +inf), cnt计数素数个数, num -> res, if M <= cnt <= N
   3. 重置cnt计数器，每10个换行
 */

int basicLevel1013() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1013.txt", "r", stdin);
#endif
    int m, n, num = 2, cnt = 0;
    cin >> m >> n;
    vector<int> nums;
    while (cnt < n) {
        if (isPrime(num)) {
            cnt++;
            if (cnt >= m) nums.push_back(num);
        }
        num++;
    }
    cnt = 0;
    for (int x: nums) {
        cnt++;
        if (cnt % 10 != 1) printf(" ");
        printf("%d", x);
        if (cnt % 10 == 0) printf("\n");
    }
    return 0;
}
