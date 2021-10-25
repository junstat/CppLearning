//
// Created by jun on 2021/1/12.
//

#include "BasicLevel.h"

/*
   1. 读入 n: int
   2. n -> int nums[3]
   3. nums[2]个B, nums[1]个S, 1 ~ nums[0]
 */
int basicLevel1006() {
#ifdef ONLINE_JUDGE
#else
    freopen("1006.input", "r", stdin);
#endif
    int n, i = 0, nums[3] = {0};
    scanf("%d", &n);
    while (n) {
        nums[i++] = n % 10;
        n /= 10;
    }
    for (i = 0; i < nums[2]; i++)
        cout << 'B';
    for (i = 0; i < nums[1]; i++)
        cout << 'S';
    for (i = 1; i <= nums[0]; i++)
        cout << i;
    return 0;
}