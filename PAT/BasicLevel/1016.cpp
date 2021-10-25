//
// @Time   : 2021/1/16 12:16
// @Author : junstat@163.com

#include "BasicLevel.h"

int basicLevel1016() {
#ifdef ONLINE_JUDGE
#else
    freopen("1016.input", "r", stdin);
#endif
    string A, B;
    char Da, Db;
    int Pa = 0, Pb = 0;
    cin >> A >> Da >> B >> Db;
    for (auto c : A) {
        if (c == Da) Pa = 10 * Pa + c - '0';
    }
    for (auto c : B) {
        if (c == Db) Pb = 10 * Pb + c - '0';
    }
    printf("%d", Pa + Pb);
    return 0;
}