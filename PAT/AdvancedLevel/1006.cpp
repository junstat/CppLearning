//
// Created by jun on 2020/5/7.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1006.txt", "r", stdin);
#endif
    int m;
    string idNumbers, singIn, singOut, earlyId, lateId, earlyTime = "23:59:59", lateTime = "00:00:00";
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        cin >> idNumbers >> singIn >> singOut;
        if (singIn < earlyTime) {
            earlyTime = singIn;
            earlyId = idNumbers;
        }
        if (singOut > lateTime) {
            lateTime = singOut;
            lateId = idNumbers;
        }
    }
    cout << earlyId << " " << lateId;
    return 0;
}

