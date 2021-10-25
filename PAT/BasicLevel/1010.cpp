//
// @Time   : 2021/1/12 21:36
// @Author : junstat@163.com

#include "BasicLevel.h"

/*
   (ax^b)' = a*b*x^(b-1)
   故 读入 a b
   输出 a*b b-1
   注意考虑, 若输入 0 0 的情况
 */
int basicLevel1010() {
#ifdef ONLINE_JUDGE
#else
    freopen("1010.input", "r", stdin);
#endif
    int a, b, notFirstPrint = 0;
    while (cin >> a >> b)
        if (b) {
            if (notFirstPrint) cout << " ";
            cout << a * b << " " << b - 1;
            notFirstPrint = 1;
        }
    if (!notFirstPrint) cout << "0 0";
    return 0;
}