//
// @Time   : 2021/1/13 20:45
// @Author : junstat@163.com

#include "BasicLevel.h"

/*
   注意范围即可
 */
int basicLevel1011() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1011.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    long long a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (i) printf("\n");
        printf("Case #%d: %s", i+1, a + b > c ? "true" : "false");
    }
    return 0;
}

