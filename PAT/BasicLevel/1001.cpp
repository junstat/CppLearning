//
// Created by jun on 2021/1/11.
//
#include "BasicLevel.h"

/*
 * n /= 2, if n %2 == 0
 * n = (3n+1) /2, else
 */
int basicLevel1001() {
#ifdef ONLINE_JUDGE
#else
    freopen("1001.input", "r", stdin);
#endif
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
        step++;
    }
    printf("%d", step);
    return 0;
}
